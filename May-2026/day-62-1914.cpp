#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void rotate_grid(int &r, int &m, int &n, vector<vector<int>> &grid, int k)
    {
        vector<int> rot_arr;
        for (int j = r; j < n - r - 1; j++)
        {
            rot_arr.push_back(grid[r][j]);
        }
        for (int i = r; i < m - r - 1; i++)
        {
            rot_arr.push_back(grid[i][n - r - 1]);
        }
        for (int j = n - r - 1; j > r; j--)
        {
            rot_arr.push_back(grid[m - r - 1][j]);
        }
        for (int i = m - r - 1; i > r; i--)
        {
            rot_arr.push_back(grid[i][r]);
        }
        k %= rot_arr.size();
        rotate(rot_arr.begin(), rot_arr.begin() + k, rot_arr.end());
        int start = 0;
        for (int j = r; j < n - r - 1; j++)
        {
            grid[r][j] = rot_arr[start++];
        }
        for (int i = r; i < m - r - 1; i++)
        {
            grid[i][n - r - 1] = rot_arr[start++];
        }
        for (int j = n - r - 1; j > r; j--)
        {
            grid[m - r - 1][j] = rot_arr[start++];
        }
        for (int i = m - r - 1; i > r; i--)
        {
            grid[i][r] = rot_arr[start++];
        }
    }
    vector<vector<int>> rotateGrid(vector<vector<int>> &grid, int k)
    {
        int m = grid.size();
        int n = grid[0].size();
        if (m % 2 != 0 || n % 2 != 0)
        {
            return grid;
        }
        int l = int(min(m, n)) / 2;
        for (int r = 0; r < l; r++)
        {
            rotate_grid(r, m, n, grid, k);
        }
        return grid;
    }
};
