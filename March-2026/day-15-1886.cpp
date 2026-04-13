#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void rotate(vector<vector<int>> &mat)
    {
        for (int i = 0; i < mat.size(); i++)
        {
            for (int j = i; j < mat.size(); j++)
            {
                swap(mat[i][j], mat[j][i]);
            }
        }
        for (int i = 0; i < mat.size(); i++)
        {
            reverse(mat[i].begin(), mat[i].end());
        }
    }
    bool findRotation(vector<vector<int>> &mat, vector<vector<int>> &target)
    {
        for (int i = 0; i < 4; i++)
        {
            if (mat == target)
                return true;
            rotate(mat);
        }
        return false;
    }
};