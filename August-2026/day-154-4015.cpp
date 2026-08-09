#include <bits/stdc++.h>
using namespace std;
// * dfs/bfs
class Solution
{
public:
    typedef long long ll;
    long long weightedSum(vector<int> &parent, vector<int> &nums)
    {
        int n = parent.size();
        // adj list
        unordered_map<int, vector<int>> adj;
        vector<int> depth(n, 0);
        for (int i = 0; i < n; i++)
        {
            adj[parent[i]].push_back(i);
        }
        queue<int> pq;
        int d = 0;
        int h = 0;
        depth[0] = 0;
        pq.push(0);
        while (!pq.empty())
        {
            int node = pq.front();
            pq.pop();
            h = max(h, depth[node]);
            for (int child : adj[node])
            {
                depth[child] = depth[node] + 1;
                pq.push(child);
            }
        }
        ll sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += (ll)nums[i] * ((ll)h - depth[i] + 1) * 1LL;
        }
        return sum;
    }
};
