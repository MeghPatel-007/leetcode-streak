#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int m, n;
    vector<vector<int>> vis;

    bool dfs(int r, int c, int pr, int pc, vector<vector<char>> &grid)
    {
        vis[r][c] = 1;

        int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        for (auto &d : dirs)
        {
            int nr = r + d[0];
            int nc = c + d[1];

            if (nr < 0 || nc < 0 || nr >= m || nc >= n)
                continue;
            if (grid[nr][nc] != grid[r][c])
                continue;

            if (!vis[nr][nc])
            {
                if (dfs(nr, nc, r, c, grid))
                    return true;
            }
            else if (nr != pr || nc != pc)
            {
                return true;
            }
        }

        return false;
    }

    bool containsCycle(vector<vector<char>> &grid)
    {
        m = grid.size();
        n = grid[0].size();

        vis.assign(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (!vis[i][j])
                {
                    if (dfs(i, j, -1, -1, grid))
                        return true;
                }
            }
        }

        return false;
    }
};
