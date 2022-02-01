#include "src/lib/cpplib.h"

#include <map>
#include <vector>

#include "gtest/gtest.h"

// Add your own tests in this file
TEST(Q5_Student, ReturnIntro) {
  CPPLib s;
  std::string expected = "My name: Yixiang Zheng \nMy email: yzheng01@usc.edu\nMy major: ECE";
  std::string actual = s.PrintIntro();
  EXPECT_EQ(expected, actual);
}