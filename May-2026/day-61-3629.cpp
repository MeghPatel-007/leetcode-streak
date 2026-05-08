#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> buildSPF(int mx)
    {
        vector<int> spf(mx + 1);

        for (int i = 0; i <= mx; i++)
            spf[i] = i;

        for (long long i = 2; i * i <= mx; i++)
        {
            if (spf[i] == i)
            {
                for (long long j = i * i; j <= mx; j += i)
                {
                    if (spf[j] == j)
                        spf[j] = i;
                }
            }
        }

        return spf;
    }

    int minJumps(vector<int> &nums)
    {

        int n = nums.size();

        if (n == 1)
            return 0;

        int mx = *max_element(nums.begin(), nums.end());

        vector<int> spf = buildSPF(mx);

        unordered_map<int, vector<int>> mp;

        for (int i = 0; i < n; i++)
        {

            int x = nums[i];

            while (x > 1)
            {

                int p = spf[x];

                mp[p].push_back(i);

                while (x % p == 0)
                    x /= p;
            }
        }

        vector<int> dist(n, -1);

        queue<int> q;

        q.push(0);

        dist[0] = 0;

        while (!q.empty())
        {

            int i = q.front();
            q.pop();

            int d = dist[i];

            if (i == n - 1)
                return d;

            if (i - 1 >= 0 && dist[i - 1] == -1)
            {
                dist[i - 1] = d + 1;
                q.push(i - 1);
            }

            if (i + 1 < n && dist[i + 1] == -1)
            {
                dist[i + 1] = d + 1;
                q.push(i + 1);
            }

            int val = nums[i];

            if (val > 1 && spf[val] == val)
            {

                for (int nxt : mp[val])
                {

                    if (dist[nxt] == -1)
                    {
                        dist[nxt] = d + 1;
                        q.push(nxt);
                    }
                }

                mp[val].clear();
            }
        }

        return -1;
    }
};
