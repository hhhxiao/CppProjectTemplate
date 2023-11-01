#include "add.h"
#include "gtest/gtest.h"

TEST(AdderTest, BasicAssertions) {
  EXPECT_EQ(add(1, 1), 2);
  EXPECT_EQ(add(1, 2), 3);
  EXPECT_EQ(add(1, -1), 0);
  EXPECT_EQ(add(0, 0), 0);
}
