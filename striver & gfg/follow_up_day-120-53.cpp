#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> &arr)
{
    int maxi = INT_MIN;
    int sum = 0;
    int x = 0, y = 0;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (maxi < sum)
        {
            maxi = sum;
            y = i;
        }
        if (sum < 0)
        {
            sum = 0;
            x = i + 1;
        }
    }
    vector<int> ans;
    for (int i = x; i <= y; i++)
    {
        ans.push_back(arr[i]);
    }
    return ans;
}

int main()
{
    // testcase-1
    vector<int> arr = {5,4,-1,7,8};
        // {-2, -3, 4, -1, -2, 1, 5, -3};
        vector<int> ans = solution(arr);
    for (int a : ans)
    {
        cout << a << " ";
    }
    return 0;
}
