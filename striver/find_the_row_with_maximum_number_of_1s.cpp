#include <bits/stdc++.h>
using namespace std;

int solution(vector<vector<int>> &matrix, int &n, int &m)
{
    int totalMax1s = 0;
    int idx = 0;
    for (int i = 0; i < n; i++)
    {
        int l = 0;
        int r = m - 1;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (matrix[i][mid] == 1)
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        if (totalMax1s < m - l)
        {
            totalMax1s = m - l;
            idx = i;
        }
    }
    return idx;
}

int main()
{
    // testcase-1
    vector<vector<int>> arr = {{0, 0, 1, 1, 1},
                               {0, 0, 0, 0, 0},
                               {0, 1, 1, 1, 1},
                               {0, 0, 0, 0, 0},
                               {0, 1, 1, 1, 1}};
    int n = 5;
    int m = 5;
    cout << solution(arr, n, m);
    return 0;
}
