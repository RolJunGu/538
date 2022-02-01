// NOTE: Add your own q2 tests in this file
#include "src/lib/cpplib.h"

#include <vector>

#include "gtest/gtest.h"

TEST(Question2Test, NullInputs)
{
    CPPLib s;
    std::vector<int> A;
    double expected = -1;
    EXPECT_EQ(expected, s.FindAverage(A));
}

TEST(Question2Test, NegtiveInputs)
{
    CPPLib s;
    std::vector<int> A = {-1, -2, -3, -4};
    double expected = -2.5;
    EXPECT_EQ(expected, s.FindAverage(A));
}

TEST(Question2Test, SingleInputs)
{
    CPPLib s;
    std::vector<int> A = {1};
    double expected = 1;
    EXPECT_EQ(expected, s.FindAverage(A));
}

TEST(Question2Test, PositiveInputs)
{
    CPPLib s;
    std::vector<int> A = {1, 2, 3, 4};
    double expected = 2.5;
    EXPECT_EQ(expected, s.FindAverage(A));
}

TEST(Question2Test, MixedInputs)
{
    CPPLib s;
    std::vector<int> A1 = {1, 2, -1, -2};
    std::vector<int> A2 = {10, 9, -6};
    double expected1 = 0;
    double expected2 = 13./3;
    EXPECT_EQ(expected1, s.FindAverage(A1));
    EXPECT_EQ(expected2, s.FindAverage(A2));
}