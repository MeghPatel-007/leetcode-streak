#include <bits/stdc++.h>
using namespace std;

//* modular exponentation algo
class Solution
{
public:
    int superPow(int a, vector<int> &b)
    {
        if (a == 1)
            return 1;
        int MOD = 1337;
        int phi = 1140;
        int exponent = 0;

        //* exp reduction using euler thm
        for (int digit : b)
        {
            exponent = (10 * exponent + digit) % phi;
        }
        if (exponent == 0)
        {
            exponent = phi;
        }

        //* modular exponentation algo
        int result = 1;
        a %= MOD;
        while (exponent > 0)
        {
            if (exponent % 2 == 1)
            {
                result = (result * a) % MOD;
            }
            a = (a * a) % MOD;
            exponent /= 2;
        }
        return result;
    }
};
