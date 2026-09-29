#include "cbc/version.hpp"

#include <gtest/gtest.h>

TEST(VersionTest, ReturnExpectedVersion) { EXPECT_EQ(cbc::version(), "0.1.0"); }
