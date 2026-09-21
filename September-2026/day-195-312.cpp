#include <bits/stdc++.h>
using namespace std;

// * Chain Matrix Multiplication
class Solution
{
public:
    int maxCoins(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> A(n + 2, 1);
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
        for (int i = 0; i < n; i++)
            A[i + 1] = nums[i];
        for (int len = 2; len <= n + 1; len++)
        {
            for (int i = 0; i <= n - len + 1; i++)
            {
                int j = i + len;
                for (int k = i + 1; k < j; k++)
                {
                    dp[i][j] = max(dp[i][j], dp[i][k] + dp[k][j] + A[i] * A[k] * A[j]);
                }
            }
        }
        return dp[0][n + 1];
    }
};
