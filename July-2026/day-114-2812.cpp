#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
    bool check(vector<vector<int>> &disNearestTheif, int sf, int n)
    {
        queue<pair<int, int>> que;
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        // 0,0 => n-1,n-1;
        que.push({0, 0});
        visited[0][0] = true;
        if (disNearestTheif[0][0] < sf)
            return false;
        while (!que.empty())
        {
            int curr_i = que.front().first;
            int curr_j = que.front().second;
            que.pop();
            if (curr_i == n - 1 && curr_j == n - 1)
            {
                return true;
            }

            for (vector<int> &dir : directions)
            {
                int new_i = curr_i + dir[0];
                int new_j = curr_j + dir[1];
                if (new_i >= 0 && new_i < n && new_j >= 0 && new_j < n && visited[new_i][new_j] == false)
                {
                    if (disNearestTheif[new_i][new_j] < sf)
                    {
                        continue;
                    }
                    que.push({new_i, new_j});
                    visited[new_i][new_j] = true;
                }
            }
        }
        return false;
    }
    int maximumSafenessFactor(vector<vector<int>> &grid)
    {
        // if(grid[0][0]==1)return 0;
        int n = grid.size();

        // step-1 : precalculate grid
        vector<vector<int>> disNearestTheif(n, vector<int>(n, -1));
        queue<pair<int, int>> que;
        vector<vector<bool>> visited(n, vector<bool>(n, false));

        // push all cells in queue where thief are present
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    que.push({i, j});
                    visited[i][j] = true;
                }
            }
        }

        int lvl = 0;
        while (!que.empty())
        {
            int size = que.size();
            while (size--)
            {
                int curr_i = que.front().first;
                int curr_j = que.front().second;
                que.pop();
                disNearestTheif[curr_i][curr_j] = lvl;
                for (vector<int> &dir : directions)
                {
                    int new_i = curr_i + dir[0];
                    int new_j = curr_j + dir[1];
                    if (new_i < 0 || new_i >= n || new_j < 0 || new_j >= n || visited[new_i][new_j] == true)
                    {
                        continue;
                    }
                    que.push({new_i, new_j});
                    visited[new_i][new_j] = true;
                }
            }
            lvl++;
        }

        // step-2 : binary search on sf
        int l = 0;
        int r = 400;
        int result = 0;
        while (l <= r)
        {
            int mid_sf = l + (r - l) / 2;
            if (check(disNearestTheif, mid_sf, n))
            {
                result = mid_sf;
                l = mid_sf + 1;
            }
            else
            {
                r = mid_sf - 1;
            }
        }
        return result;
    }
};
