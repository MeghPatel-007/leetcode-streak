#include <bits/stdc++.h>
using namespace std;

// * recursion,array,loops
class Solution
{
public:
    bool threeFibonacciSum(int n)
    {
        long long f0 = 0, f1 = 1, f2 = 1;
        while (f0 + f1 + f2 <= n)
        {
            if (f0 + f1 + f2 == n)
            {
                return true;
            }
            f0 = f1;
            f1 = f2;
            f2 = f0 + f1;
        }
        return false;
    }
};
