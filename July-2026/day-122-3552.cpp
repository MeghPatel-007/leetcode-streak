#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<bool> pathExistenceQueries(int n, vector<int> &nums, int maxDiff, vector<vector<int>> &queries)
    {
        // adjaceny list
        // unordered_map<int, vector<int>> adj(n);
        // for (int i = 1; i < n; i++)
        // {
        //     int diff = nums[i] - nums[i - 1];
        //     if (diff <= maxDiff)
        //     {
        //         adj[i].push_back(i - 1);
        //         adj[i - 1].push_back(i);
        //     }
        // }
        // int m = queries.size();

        // vector<bool> answer(m, false);
        // queue<int> q;
        // vector<bool> visited(m + 1, false);
        // for (int i = 0; i < m; i++)
        // {
        //     fill(visited.begin(), visited.end(), false);
        //     int s = queries[i][0];
        //     int e = queries[i][1];
        //     visited[s] = true;
        //     if (e - s == 1)
        //     {
        //         vector<int> elements = adj[s];
        //         for (auto &el : elements)
        //         {
        //             if (el == e)
        //                 answer[i] = true;
        //         }
        //     }
        //     else
        //     {
        //         q.push(s);
        //         while (!q.empty())
        //         {
        //             int node = q.front();
        //             q.pop();
        //             if (node == e){
        //                 answer[i] = true;
        //                 break;
        //             }
        //             vector<int> v = adj[node];
        //             for (auto &el : v)
        //             {
        //                 if (!visited[el])
        //                 {
        //                     q.push(el);
        //                     visited[el] = true;
        //                 }
        //             }
        //         }
        //     }
        // }
        // return answer;

        vector<int> chain(n);
        int c_index = 0;
        chain[0] = 0;
        for (int i = 1; i < n; i++)
        {
            int diff = nums[i] - nums[i - 1];
            if (diff > maxDiff)
                ++c_index;
            chain[i] = c_index;
        }
        int m = queries.size();
        vector<bool> answer(m, false);
        for (int i = 0; i < m; i++)
        {
            int s = queries[i][0];
            int e = queries[i][1];
            if(chain[s]==chain[e])answer[i]=true;
        }
        return answer;
    }
};
