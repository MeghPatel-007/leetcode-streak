#include <bits/stdc++.h>
using namespace std;

// * bit manipulation,xor operator
class Solution
{
public:
    int solve(int n)
    {
        if (n % 4 == 1)
            return 1;
        if (n % 4 == 2)
            return n + 1;
        if (n % 4 == 3)
            return 0;
        return n;
    }
    int findXOR(int l, int r)
    {
        return solve(l - 1) ^ solve(r);
    }
};
