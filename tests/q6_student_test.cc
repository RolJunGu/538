#include "src/lib/cpplib.h"

#include <map>
#include <vector>

#include "gtest/gtest.h"

// Add your own tests in this file
TEST(Q6_Student, NormalInputs) {
  CPPLib s;
  std::vector<int> A1 = {1, 2}, A2 = {3, 4}, B1 = {5, 6}, B2 = {7, 8}, C1 = {9, 10};
  std::vector<int> actual, Expected = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::vector<std::vector<int>> A = {A1, A2}, B = {B1, B2}, C = {C1} ;
  std::vector<std::vector<std::vector<int>>> Test = {A, B, C};
  actual = s.Flatten3DVector(Test);
  EXPECT_EQ(Expected, actual);
}

TEST(Q6_Student, PartialEmpty) {
  CPPLib s;
  std::vector<int> A1 = {1, 2}, A2, B1 = {5}, B2 = {6}, B3, C1 = {7, 8}, C2;
  std::vector<int> actual, Expected = {1, 2, 5, 6, 7, 8};
  std::vector<std::vector<int>> A = {A1, A2}, B = {B1, B2, B3}, C = {C1, C2} ;
  std::vector<std::vector<std::vector<int>>> Test = {A, B, C};
  actual = s.Flatten3DVector(Test);
  EXPECT_EQ(Expected, actual);
}

TEST(Q6_Student, TotalEmpty) {
  CPPLib s;
  std::vector<int> A1, A2, B1, B2, C1;
  std::vector<int> actual, Expected;
  std::vector<std::vector<int>> A = {A1, A2}, B = {B1, B2}, C = {C1} ;
  std::vector<std::vector<std::vector<int>>> Test = {A, B, C};
  actual = s.Flatten3DVector(Test);
  EXPECT_EQ(Expected, actual);
}

