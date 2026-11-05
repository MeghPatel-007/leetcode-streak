#include <bits/stdc++.h>
using namespace std;

// * bit manipulation,2's complement
class Solution
{
public:
    vector<int> singleNumber(vector<int> &nums)
    {
        int xorResult = 0;
        for (int num : nums)
        {
            xorResult ^= num;
        }

        uint32_t bits = static_cast<uint32_t>(xorResult); // unsigned arithmetic in C++ is defined to wrap around modulo 2³², so overflow is never undefined behavior
        uint32_t mask = bits & (~bits + 1u);              // two’s complement

        int group1 = 0;
        int group2 = 0;

        for (int num : nums)
        {
            if ((static_cast<uint32_t>(num) & mask) != 0)
            {
                group1 ^= num;
            }
            else
            {
                group2 ^= num;
            }
        }

        return {group1, group2};
    }
};
