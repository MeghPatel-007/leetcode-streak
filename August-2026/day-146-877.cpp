#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int t[501][501];
    int solve(int i, int j, vector<int> &piles)
    {
        if (i > j)
            return 0;
        if (i == j)
            return piles[i];
        if (t[i][j] != -1)
        {
            return t[i][j];
        }
        int task_i = piles[i] + min(solve(i + 2, j, piles), solve(i + 1, j - 1, piles));
        int task_j = piles[j] + min(solve(i + 1, j - 1, piles), solve(i, j - 2, piles));
        return t[i][j] = max(task_i, task_j);
    }
    bool stoneGame(vector<int> &piles)
    {
        memset(t, -1, sizeof(t));
        int n = piles.size();
        int alice = solve(0, n - 1, piles);
        int total = accumulate(begin(piles), end(piles), 0);
        int bob = total - alice;
        return alice > bob;
    }
};

// it could be O(1) as it is true all the time;
