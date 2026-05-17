#include <bits/stdc++.h>
using namespace std;
//* BFS
class Solution
{
public:
    bool canReach(vector<int> &arr, int start)
    {
        int n = arr.size();
        vector<int> vis(n, 0);
        vis[start] = 1;
        queue<int> q;
        q.push(start);
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            if (arr[node] == 0)
            {
                return true;
            }
            int left = node + arr[node];
            int right = node - arr[node];
            if ((0 <= left && left < n) && !vis[left])
            {
                vis[left] = 1;
                q.push(left);
            }
            if ((0 <= right && right < n) && !vis[right])
            {
                vis[right] = 1;
                q.push(right);
            }
        }
        return false;
    }
};
