#include <bits/stdc++.h>
using namespace std;

int solution(int n, int x, vector<int> &arr)
{
    int l = 0;
    int r = n - 1;
    int ans = -1;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (mid > n)
            break;
        if (arr[mid] > x)
        {
            ans = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return ans;
}

int main()
{
    // testcase-1
    vector<int> arr = {3,5,8,9,15,19};
    int n = 6;
    int x = 9;
    cout << solution(n,x,arr);
    return 0;
}
