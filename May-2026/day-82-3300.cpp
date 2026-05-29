#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minElement(vector<int> &nums)
    {
        int mini = 1e9;
        for (int &n : nums)
        {
            int sum = 0;
            while (n)
            {
                sum += n % 10;
                n /= 10;
            }
            mini = min(mini, sum);
        }
        return mini;
    }
};
