#include <bits/stdc++.h>
using namespace std;

int solution(int target, vector<int> &arr)
{
    int l = 0;
    int r = arr.size() - 1;
    int first = 0, last = 0;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (mid > arr.size())
            return 0;
        if (arr[mid] == target)
        {
            first = mid;
            r = mid - 1;
        }
        else if (arr[mid] < target)
            l = mid + 1;
        else
            r = mid - 1;
    }
    l = 0;
    r = arr.size() - 1;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (mid > arr.size())
            return 0;
        if (arr[mid] == target)
        {
            last = mid;
            l = mid + 1;
        }
        else if (arr[mid] < target)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return last - first + 1;
}

int main()
{
    // testcase-1
    vector<int> arr = {2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 4};
    int target = 4;
    cout << solution(target, arr);
    return 0;
}
