#include <bits/stdc++.h>
using namespace std;

// * bit manipulation
class Solution
{
public:
    bool isPowerOfThree(int n)
    {
        // 3^19 => 1162261467 for 32-bit number
        return n > 0 && 1162261467 % n == 0;
    }
};
