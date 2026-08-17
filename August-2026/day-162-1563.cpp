#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int t[501][501];
    int solve(vector<int> &cumSum, int l, int r)
    {
        if (l >= r)
        {
            return 0;
        }
        if (t[l][r] != -1)
        {
            return t[l][r];
        }
        int score = 0;
        for (int mid = l; mid <= r - 1; mid++)
        {
            int leftSum = cumSum[mid] - ((l - 1 >= 0) ? cumSum[l - 1] : 0);
            int rightSum = cumSum[r] - cumSum[mid];
            if (leftSum < rightSum)
            {
                score = max(score, leftSum + solve(cumSum, l, mid));
            }
            else if (leftSum > rightSum)
            {
                score = max(score, rightSum + solve(cumSum, mid + 1, r));
            }
            else
            {
                score = max({score, rightSum + solve(cumSum, mid + 1, r), leftSum + solve(cumSum, l, mid)});
            }
        }
        return t[l][r] = score;
    }
    int stoneGameV(vector<int> &stoneValue)
    {
        int n = stoneValue.size();
        vector<int> cumSum(n, 0);
        cumSum[0] = stoneValue[0];
        for (int i = 1; i < n; i++)
        {
            cumSum[i] = cumSum[i - 1] + stoneValue[i];
        }
        memset(t, -1, sizeof(t));
        return solve(cumSum, 0, n - 1);
    }
};
