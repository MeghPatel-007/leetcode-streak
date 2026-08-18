#include <bits/stdc++.h>
using namespace std;

// * tc => O(n) , Math
class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int n = nums.size();
        int sum = n * (n + 1) / 2;
        return sum - accumulate(begin(nums), end(nums), 0);
    }
};
