#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool findSafeWalk(vector<vector<int>> &grid, int health)
    {
        int n = grid.size();
        int m = grid[0].size();
        if (grid[0][0] == 1)
            health--;
        if (health <= 0)
            return false;
        vector<vector<int>> visited(n, vector<int>(m, -1));
        queue<tuple<int, int, int>> que;
        vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        que.push({0, 0, health});
        visited[0][0] = health;
        while (!que.empty())
        {
            auto [first, second, third] = que.front();
            int curr_i = first;
            int curr_j = second;
            int remaininghealth = third;
            que.pop();
            if (curr_i == n - 1 && curr_j == m - 1 && remaininghealth > 0)
                return true;
            for (vector<int> &dir : directions)
            {
                int new_i = curr_i + dir[0];
                int new_j = curr_j + dir[1];
                int new_remaininghealth;
                if (new_i >= 0 && new_i < n && new_j >= 0 && new_j < m)
                {
                    new_remaininghealth = remaininghealth - grid[new_i][new_j];
                    if (new_remaininghealth <= 0 || visited[new_i][new_j] >= new_remaininghealth)
                        continue;
                }
                else
                    continue;

                que.push({new_i, new_j, new_remaininghealth});
                visited[new_i][new_j] = max(visited[new_i][new_j], new_remaininghealth);
            }
        }
        return false;
    }
};
