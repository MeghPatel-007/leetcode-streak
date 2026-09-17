#include <bits/stdc++.h>
using namespace std;

// * binary exponentation
class Solution
{
public:
    const int MOD = 1e9 + 7;
    int binaryExpo(long long base, long long exp)
    {
        int ans = 1;
        while (exp > 0)
        {
            if (exp % 2 == 1)
            {
                ans = (ans * base) % MOD;
                exp--;
            }
            else
            {
                base = (base * base) % MOD;
                exp = exp / 2;
            }
        }
        return ans;
    }
    int countGoodNumbers(long long n)
    {
        return (long long)binaryExpo(5, (n + 1) / 2) * binaryExpo(4, n / 2) % MOD;
    }
};
