#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long sumAndMultiply(int n)
    {
        long long new_n = 0;
        long long sum = 0;
        long long x = 0;
        while (n != 0)
        {
            int r = n % 10;
            if (r != 0)
            {
                new_n = r * pow(10, x) + new_n;
                sum += r;
                x++;
            }
            n = n / 10;
        }
        return new_n * sum;
    }
};
