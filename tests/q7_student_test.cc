#include "src/lib/cpplib.h"

#include <map>
#include <vector>

#include "gtest/gtest.h"

// Add your own tests in this file


TEST(Q7_Student, LessThan5Inputs) {
  CPPLib s;
  int actual1 = s.climbStairs(4), actual2 = s.climbStairs(5);
  int expected1 = 5, expected2 = 8;

  EXPECT_EQ(expected1, actual1);
  EXPECT_EQ(expected2, actual2);
}
// n = 5
// 11111
// 1112
// 1121
// 1211
// 122
// 2111
// 212
// 221

TEST(Q7_Student, MoreThan10Inputs) {
  CPPLib s;
  int actual1 = s.climbStairs(12), actual2 = s.climbStairs(14);
  int expected1 = 233, expected2 = 610;

  EXPECT_EQ(expected1, actual1);
  EXPECT_EQ(expected2, actual2);
}


TEST(Q7_Student, ZeroInputs) {
  CPPLib s;
  int actual = s.climbStairs(0);
  int expected = 0;

  EXPECT_EQ(expected, actual);

}

TEST(Q7_Student, InvalidInputs) {
  CPPLib s;
  int actual1 = s.climbStairs(-1);
  int expected1 = -1;
  int actual2 = s.climbStairs(46);
  int expected2 = -1;

  EXPECT_EQ(expected1, actual1);
  EXPECT_EQ(expected2, actual2);
}