#include <bits/stdc++.h>
using namespace std;

// * binary search on 2d matrix
class Solution
{
public:
    int maxElement(int j, int n, vector<vector<int>> &mat)
    {
        int mx = INT_MIN;
        int idx = 0;
        for (int i = 0; i < n; i++)
        {
            if (mx < mat[i][j])
            {
                mx = mat[i][j];
                idx = i;
            }
        }
        return idx;
    }
    vector<int> findPeakGrid(vector<vector<int>> &mat)
    {
        int n = mat.size();
        int m = mat[0].size();
        int l = 0;
        int r = m - 1;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            int i = maxElement(mid, n, mat);
            if (mat[i][mid] > (mid + 1 < m ? mat[i][mid + 1] : -1) && mat[i][mid] > (mid - 1 >= 0 ? mat[i][mid - 1] : -1))
            {
                return {i, mid};
            }
            else if (mat[i][mid] < mat[i][mid + 1])
            {
                l = mid + 1;
            }
            else if (mat[i][mid] < mat[i][mid - 1])
            {
                r = mid - 1;
            }
        }
        return {-1, -1};
    }
};
