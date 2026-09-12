#include <bits/stdc++.h>
using namespace std;

// * dp,bfs,shortest path,dijkstra's algo
class Solution
{
public:
    vector<int> memo;
    int solve(int target, int n)
    {
        if (target == n)
            return 0;
        if (memo[target] != -1)
            return memo[target];
        int mindays = 1e9;
        for (int k = 1;; k++)
        {
            int points = k * (k + 1) / 2;
            if (target + points > n)
                break;
            int nextTarget = target + points;
            int cost = (nextTarget == n) ? k : k + 1;
            mindays = min(mindays, cost + solve(nextTarget, n));
        }
        return memo[target] = mindays;
    }
    int minDays(int n)
    {
        memo.assign(n + 1, -1);
        return solve(0, n);
    }
};
