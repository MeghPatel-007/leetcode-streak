#include <bits/stdc++.h>
using namespace std;

int blackBox(vector<int> &arr, int mid)
{
    return upper_bound(begin(arr), end(arr), mid) - begin(arr);
}

int solution(vector<vector<int>> &arr, int &n, int &m)
{
    int l = arr[0][0];
    int r = arr[0][m - 1];
    for (int i = 0; i < n; i++)
    {
        l = min(l, arr[i][0]);
        r = max(r, arr[i][m - 1]);
    }
    int req = (n * m) / 2;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            count += blackBox(arr[i], mid);
        }
        if (count <= req)
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    return l;
}

int main()
{
    // testcase-1
    vector<vector<int>> arr = {
        {1, 5, 7, 9, 11},
        {2, 3, 4, 5, 10},
        {9, 10, 12, 14, 16}};
    int n = arr.size();
    int m = arr[0].size();
    cout << solution(arr, n, m);
    return 0;
}
