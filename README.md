
# HW1 EE538 - Computing Principles for Electrical Engineers

- Please clone the repository, edit [README.md](README.md) to answer the questions, and fill up functions to finish the homework.
- For non-coding questions, fill out the answers below each question. Please write your answer there.
- For coding questions, please make sure that your code can run ```bazel run/test```. In this homework, you will need to fill up [cpplib.cc](src/lib/cpplib.cc) and tests in [tests](tests). **Do Not change or modify any given function names and input or output formats in both [cpplib.cc](src/lib/cpplib.cc) and tests in [tests](tests). Unexpected changes will result in **zero** credit.**
- For coding questions, there is a black box test for each question. All points are only based on passing the test cases or not (i.e. we don't grade your work by your source code). So, try to do comprehensive testing before your final submission.
- For submission, please push your answers to Github before the deadline.
- Deadline: **Tuesday, Feb 1st by 12 pm**
- Total: 130 points. 100 points is considered full credit.

## Question 1 (10 Points. Easy)

Create an account on GitHub and Stack Overflow and paste the link to your profile.

GitHub profile link:  https://github.com/RolJunGu

Stack Overflow profile link:  https://stackoverflow.com/users/18032695/gary?tab=profile

## Question 2 (20 Points. Medium)

Write a function called **FindAverage**, which returns the average of the inputs of a vector of integers. Use the steps the following steps:
1. Clearly specify input and output.
2. Write some example input and outputs. Try to cover corner cases. Feel free to make reasonable assumptions for the corner cases.
3. Implement your algorithm.
4. Write several unit tests that cover all corner cases, and test your algorithm using bazel.
You will need to only submit your algorithm implementation and the unit tests.

## Question 3 (20 Points. Medium)

Compute the worst case run-time complexity of the below functions. Please provide both the computation process and final result for full credit.

```cpp
void Example1(int n) {
   int i = 1;
   while (i < n) {
       i *= 2;
   }
}
```

Answer: 
The i can be 1, 2, 4 ... n. So the number of i is log(n)
T(n) = 1 + log(n) * (1 + 1) = 2log(n) + 1 = O(log(n))


```cpp
void Example2(int n) {
   int count = 0;
   for (int i = 1; i <= n; i = i * 2) {
       for (int j = 1; j <= n; j++) {
           for (int k = 1; k <= n; k = k * 3) {
               count++;
           }
       }
   }
}
```

Answer: 
For the first loop, it will repeat log(n) times (same with above).
For the second loop, it will repeat n times.
For the third loop, the k can be 1, 3, 9...n. So it will repeat log(n) times.
T(n) = 1 + log(n) * (2 + n * (2 + log(n) * (2+1))) = 1 + 2log(n) + 2nlog(n) + 3n * log(n)^2 = O(n * log(n)^2)


```cpp
void Example3(int n) {
   int count = 0;
   for (int i = 0; i < n; i++)
       for (int j = i; j < i*i*i; j++)
            std::cout<<"*";
}
```

Hint: Note the ```j < i*i*i``` in the inner loop and compute the cube sequence to get the final result.

Answer:

Totally it will repeat 1+2^3+...+n^3 - (1+2+...+n) = (n*(n+1)/2)^2 - n(n+1)/2 = (n^4 + 2n^3 - n^2 -2n)
T(n) = (n^4 + 2n^3 - n^2 -2n) = O(n^4)


```cpp
int Example4(int n) {
   int count = 0;
   for (int i = 1; i < n; i *= 3) {
      for (int j = n; j > 0; j /= 3) {
          for (int k = 0; k < j; k++) {
              count += 1;
          }
      }
   }
   return count;
}
```

Hint: Note the ```i /= 3``` in the outer loop and compute the geometric sequence to get the final result.

Answer:
For the first loop, it will repeat log(n) times.
For the second and third loop, j can be n, n/3, n/9...1. So this two loop will repeat 3/2(n+n^2) times
T(n) = O(n^2 * log(n))


## Question 4 (10 Points. Easy)

What does it mean when we say that the **Heap Sort (HS)** algorithm is asymptotically more efficient than the **Bubble Sort (BS)** algorithm **assuming the input is randomly ordered**? Support your choice with an explanation.


1. HS will always be a better choice for small size inputs
2. BS will always be a better choice for small size inputs
3. HS will always be a better choice for large size inputs
4. BS will always be a better choice for large size inputs
5. HS will always be a better choice for inputs of any size
6. BS will always be a better choice for inputs of any size


Answer:
I choose 3. 
Because the time complexity for HS is O(nlogn), and the time complexity for BS is O(n^2). So for large size inputs, it's obiviously that HS will always be a better choice. But for the small size, I cannot sure which one is better, cause there may be many constant operation will influence the time.

## Question 5 (15 Points. Easy)

Write a simple function ```std::string CPPLib::PrintIntro()``` in [cpplib.cc](src/lib/cpplib.cc) to print your name, email, and any information about you that you want (e.g. your major, your expertise, your interests, etc) and write a test using GTest for your function in [tests/q5_student_test.cc](tests/q5_student_test.cc). We will run your code and see your printout!

Please create your test cases and run the following command to verify the functionality of your program.

```bash
bazel test tests:q5_student_test
```

## Question 6 (25 Points. Medium)

 Write a function ```std::vector<int> CPPLib::Flatten3DVector(const std::vector< std::vector< std::vector<int> > > &input)``` in [cpplib.cc](src/lib/cpplib.cc) to flatten a 3D vector into a 1D vector.

Example:\
Input: inputs = [[[1, 2], [3, 4]], [[5], [6], []], [[7, 8]]].\
Output: result = [1, 2, 3, 4, 5, 6, 7, 8].

Write several tests using GTest for your function in [tests/q6_student_test.cc](tests/q6_student_test.cc).\
(Hint: include cases with empty vectors)

Please create your test cases and run the following command to verify the functionality of your program.
```
bazel test tests:q6_student_test
```
What is the worst case runtime complexity of your implementation?

Answer:
If I consider the input as 3 dimension data, there are 3 variables, that is n1, n2, n3.
So T(n) = n1 * n2 * n3 = O(n1*n2*n3) = O(n^3)


## Question 7 (30 Points. Medium)

Write a function ```int CPPLib::climbStairs(int n)``` in [cpplib.cc](src/lib/cpplib.cc) using recursion to find how many distinct ways you can climb to the top. Your function should accept positive numbers less than 45 and return the number of ways. Further, write several tests using GTest for your function in [tests/q7_student_test.cc](tests/q7_student_test.cc) and compute the time complexity of your implementation.

*Rules of the climb stairs*\
You are climbing a staircase. Each time you can either climb 1 or 2 steps. It takes n steps to reach the top.

If there are 0 stairs, there is 0 way to the top. For negative input, please return -1.

For example, if the stairs number is 4(n = 4), it should have 5 ways to the top.\
1 + 1 + 1 + 1\
1 + 1 + 2\
1 + 2 + 1\
2 + 1 + 1\
2 + 2

Please create your test cases and run the following command to verify the functionality of your program.

```bash
bazel test tests:q7_student_test
```
**Hint**: Try to write a recursive relationship.
What is the complexity of your implementation?

Answer:
T(n) = 2^n = O(2^n)