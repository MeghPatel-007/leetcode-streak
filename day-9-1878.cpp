#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> getBiggestThree(vector<vector<int>> &grid)
    {
        vector<long long> answer = {};
        vector<int> res = {};
        int rsize = grid.size();
        int csize = grid[0].size();
        int diagonal = max(csize, rsize);
        for (int r = 0; r < rsize; r++)
        {
            for (int c = 0; c < csize; c++)
            {
                answer.push_back(grid[r][c]);
                for (int k = 1; k < diagonal; k++)
                {
                    if (r + 2 * k >= rsize || c - k < 0 || c + k >= csize)
                        break;
                    long long int sum = 0;
                    // top -> right

                    for (int i = 0; i < k; i++)
                        sum += grid[r + i][c + i];

                    // right -> bottom

                    for (int i = 0; i < k; i++)
                        sum += grid[r + k + i][c + k - i];

                    // bottom -> left

                    for (int i = 0; i < k; i++)
                        sum += grid[r + 2 * k - i][c - i];

                    // left -> top
                    for (int i = 0; i < k; i++)
                        sum += grid[r + k - i][c - k + i];
                    answer.push_back(sum);
                }
            }
        }
        sort(answer.begin(), answer.end());
        set<long long, greater<long long>> my_set(answer.begin(), answer.end());
        vector<int> final;
        for (auto x : my_set)
        {
            final.push_back(x);
            if (final.size() == 3)
                break;
        }
        return final;
    }
};