#include <bits/stdc++.h>
using namespace std;

// * bit manipulation,xor operator
class Solution
{
public:
    int minBitFlips(int start, int goal)
    {
        int n = start ^ goal;
        int cnt = 0;
        for (int i = 0; i < 31; i++)
        {
            if (n & (1 << i))
                cnt++;
        }
        return cnt;
    }
};
