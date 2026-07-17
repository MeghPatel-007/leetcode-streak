#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> gcdValues(vector<int> &nums, vector<long long> &queries)
    {
        int mx = INT_MIN;
        for (auto &n : nums)
        {
            mx = max(mx, n);
        }
        // freq & max
        vector<long long> arr(mx + 1, 0);
        for (auto &n : nums)
        {
            arr[n]++;
            mx = max(mx, n);
        }
        // SOE => all divisible by i
        for (int i = 1; i <= mx; i++)
        {
            for (int j = 2 * i; j <= mx; j += i)
            {
                arr[i] += arr[j];
            }
        }
        // combinatorics
        for (int i = 1; i <= mx; i++)
        {
            long long cnt = arr[i];
            arr[i] = cnt * (cnt - 1) / 2;
        }

        // pair of gcd
        for (int i = mx; i >= 1; i--)
        {
            for (int j = 2 * i; j <= mx; j += i)
            {
                arr[i] -= arr[j];
            }
        }

        // prefixSum
        for (int i = 1; i <= mx; i++)
        {
            arr[i] += arr[i - 1];
        }
        // binary search
        vector<int> ans;
        for (auto &q : queries)
        {
            int l = 1;
            int r = mx;
            while (l < r)
            {
                int mid = l + (r - l) / 2;
                if (arr[mid] > q)
                {
                    r = mid;
                }
                else
                    l = mid + 1;
            }
            ans.push_back(l);
        }
        return ans;
    }
};
