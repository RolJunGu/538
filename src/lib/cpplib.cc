#include "cpplib.h"
#include "limits"

std::string CPPLib::PrintHelloWorld() { return "**** Hello World ****"; }

// NOTE: write your own function declaration q2 here
double CPPLib::FindAverage(const std::vector<int> &input){
    // The input is an array of number(data type is int).
    // The output is the average of this array. The data type is double.
    double n = input.size();
    if(!n)
    {
        return -1;
    }

    double sum = 0;
    for(auto i : input)
    {
        sum += i;
    }
    return sum / n;

}


// Question 5 Print your self-introduction
std::string CPPLib::PrintIntro() {
    // Please fill up this function.
    return "My name: Yixiang Zheng \nMy email: yzheng01@usc.edu\nMy major: ECE"; 
}

// Question 6
std::vector<int> CPPLib::Flatten3DVector(const std::vector< std::vector< std::vector<int> > > &input){
    // Please fill up this function.
    std::vector<int> res;
    for(auto i : input)
    {
        for(auto j : i)
        {
            for(auto k : j)
            {
                res.push_back(k);
            }
        }
    }
    return res;
}

// Question 7 Climbing Stairs
int CPPLib::climbStairs(int n){
    // Please fill up this function.
    if(n<0 || n>45)
    {
        return -1;
    }
    if(n <= 2)
    {
        return n;
    }
    int results;
    results = climbStairs(n-1) + climbStairs(n-2);

    return results;
}
