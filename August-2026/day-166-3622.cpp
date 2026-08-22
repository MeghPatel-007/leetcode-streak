#include <bits/stdc++.h>
using namespace std;

// * math
class Solution
{
public:
    bool checkDivisibility(int n)
    {
        long long sum = 0;
        long long mul = 1;
        int num = n;
        while (n != 0)
        {
            sum += n % 10;
            mul *= n % 10;
            n = n / 10;
        }
        return num % (sum + mul) == 0;
    }
};
