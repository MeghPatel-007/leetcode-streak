#include <bits/stdc++.h>
using namespace std;

// * bit manipulation,shift operator
class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int res = 0;
        for (int i = 0; i < 32; i++)
        {
            int sum = 0;
            for (int num : nums)
            {
                if (num & (1 << i))
                    sum++;
            }
            if (sum % 3 != 0)
                res = res | 1 << i;
        }
        return res;
    }
};
