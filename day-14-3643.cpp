#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>> &grid, int x, int y, int k)
    {
        int size = k / 2;
        for (int i = x; i < x + size; i++)
        {
            for (int j = y; j < y + k; j++)
            {
                //formula
                swap(grid[i][j], grid[x + k - 1 - (i - x)][j]);
            }
        }
        return grid;
    }
};