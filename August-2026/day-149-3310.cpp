#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>> &invocations)
    {
        unordered_map<int, vector<int>> adj;
        int m = invocations.size();
        // adjacency list
        for (int i = 0; i < m; i++)
        {
            int a = invocations[i][0];
            int b = invocations[i][1];
            adj[a].push_back(b);
        }

        queue<int> pq;
        vector<bool> infected(n, false);
        pq.push(k);
        infected[k] = true;
        while (!pq.empty())
        {
            int projects = pq.front();
            pq.pop();
            for (auto &project : adj[projects])
            {
                if (!infected[project])
                {
                    infected[project] = true;
                    pq.push(project);
                }
            }
        }
        bool can_remove = true;
        for (auto &inv : invocations)
        {
            int a = inv[0];
            int b = inv[1];
            // non-infected calling an infected
            if (!infected[a] && infected[b])
            {
                can_remove = false;
                break;
            }
        }
        vector<int> uninfected;
        for (int i = 0; i < n; i++)
        {
            if (!can_remove || !infected[i])
            {
                uninfected.push_back(i);
            }
        }
        return uninfected;
    }
};
