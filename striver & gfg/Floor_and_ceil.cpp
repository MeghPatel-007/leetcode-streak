#include <bits/stdc++.h>
using namespace std;

int floor(int n, int x, vector<int> &arr)
{
    int l = 0;
    int r = n - 1;
    int ans = -1;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (mid > n)
            break;
        if (arr[mid] <= x)
        {
            ans = mid;
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    return arr[ans];
}

int ceil(int n, int x, vector<int> &arr)
{
    int l = 0;
    int r = n - 1;
    int ans = -1;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (mid > n)
            break;
        if (arr[mid] >= x)
        {
            ans = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return arr[ans];
}

int main()
{
    // testcase-1
    vector<int> arr = {3, 4, 4, 7, 8, 10};
    int n = 6;
    int x = 8;
    cout << floor(n, x, arr);
    cout << ceil(n, x, arr);
    return 0;
}
