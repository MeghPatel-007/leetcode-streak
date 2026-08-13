#include <bits/stdc++.h>
using namespace std;

// * binary search using missing number
class Solution
{
public:
    int findKthPositive(vector<int> &arr, int k)
    {
        int n = arr.size();
        int l = 0;
        int r = n - 1;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            int missing = arr[mid] - (mid + 1);
            if (k <= missing)
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        return r + k + 1; // maths is used
        // => missing = arr[r]-(r+1)
        // => more = k - missing
        // => ans = arr[r] + more
        // =>     = arr[r] + k - arr[r] + r + 1
        // =>     = k+r+1
    }
};
