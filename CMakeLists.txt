cmake_minimum_required(VERSION 3.25)
project(cbc_gym VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

option(CBC_ENABLE_SANITIZERS "Enable address and undefined-behavior checks" OFF)
option(CBC_WARNINGS_AS_ERRORS "Treat project compiler warnings as errors" ON)

# Apply strict warnings to our targets, not to downloaded dependencies.
add_library(cbc_warnings INTERFACE)
if(MSVC)
  target_compile_options(cbc_warnings INTERFACE /W4
    $<$<BOOL:${CBC_WARNINGS_AS_ERRORS}>:/WX>)
else()
  target_compile_options(cbc_warnings INTERFACE -Wall -Wextra -Wpedantic
    $<$<BOOL:${CBC_WARNINGS_AS_ERRORS}>:-Werror>)
endif()

# Carry the sanitizer flags to both the library and programs that use it.
add_library(cbc_build_options INTERFACE)
if(CBC_ENABLE_SANITIZERS)
  if(NOT CMAKE_CXX_COMPILER_ID MATCHES "^(AppleClang|Clang|GNU)$")
    message(FATAL_ERROR "CBC_ENABLE_SANITIZERS requires Clang or GCC")
  endif()
  target_compile_options(cbc_build_options INTERFACE
    -fsanitize=address,undefined -fno-omit-frame-pointer
    -fno-sanitize-recover=all)
  target_link_options(cbc_build_options INTERFACE -fsanitize=address,undefined)
endif()

# Core library: the simulation and controller code lives here.
add_library(cbc src/version.cpp)
target_include_directories(cbc PUBLIC include)
target_compile_definitions(cbc PRIVATE CBC_VERSION="${PROJECT_VERSION}")
target_link_libraries(cbc PUBLIC cbc_build_options PRIVATE cbc_warnings)

# Small demo program.
add_executable(cbc_hello apps/cbc_hello.cpp)
target_link_libraries(cbc_hello PRIVATE cbc cbc_warnings)

# Download GoogleTest and make it available.
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.18.0.zip
  URL_HASH SHA256=63b9c77751a5b8f492486005f67533fdc58682b67476fcb91650be5958d5195a
)
FetchContent_MakeAvailable(googletest)

# Build our test program and connect its libraries.
add_executable(cbc_tests tests/version_test.cpp)
target_link_libraries(cbc_tests PRIVATE cbc cbc_warnings GTest::gtest_main)

# Let CMake's test runner find our tests.
enable_testing()
include(GoogleTest)
gtest_discover_tests(cbc_tests)
