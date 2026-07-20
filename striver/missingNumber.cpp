#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> &arr)
{
    //* tc = o(NlogN)
    // sort(arr.begin(), arr.end());
    // for (int i = 1; i < arr.size(); i++)
    // {
    //     if (arr[i] - arr[i - 1] != 1)
    //     {
    //         return arr[i] - 1;
    //     }
    // }
    // return 0;
    //* tc = o(N) sc = o(N)
    // int n = arr.size()+1;
    // vector<int> h(n + 1, 0);
    // for (int a : arr)
    // {
    //     h[a]++;
    // }
    // for (int i = 1; i <= n; i++)
    // {
    //     if (h[i] == 0)
    //         return i;
    // }
    // return -1;
    //*tc = o(N) sc= o(1)
    int n = arr.size() + 1;
    int sum = 0;
    for (int i : arr)
    {
        sum += i;
    }
    int expsum = n * (n + 1) / 2;
    return expsum - sum;
}

int main()
{
    // testcase-1
    vector<int> arr = {1, 2, 3, 5};
    cout << solution(arr);
    return 0;
}
