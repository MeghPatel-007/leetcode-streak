#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        unordered_map<int, vector<int>> mp = {
            {1, {2,3}},
            {2, {0,1}},
            {3, {2,1}},
            {4, {3,1}},
            {5, {2,0}},
            {6, {3,0}}
        };

        vector<vector<int>> vis(m, vector<int>(n, 0));

        queue<pair<int,int>> q;
        q.push({0,0});
        vis[0][0] = 1;

        int dr[4] = {-1,1,0,0};
        int dc[4] = {0,0,-1,1};

        while (!q.empty()) {
            auto [r,c] = q.front();
            q.pop();

            if (r == m-1 && c == n-1) return true;

            for (int d : mp[grid[r][c]]) {
                int nr = r + dr[d];
                int nc = c + dc[d];

                if (nr < 0 || nc < 0 || nr >= m || nc >= n) continue;
                if (vis[nr][nc]) continue;

                int rev = (d == 0 ? 1 : d == 1 ? 0 : d == 2 ? 3 : 2);

                bool ok = false;
                for (int nd : mp[grid[nr][nc]]) {
                    if (nd == rev) {
                        ok = true;
                        break;
                    }
                }

                if (!ok) continue;

                vis[nr][nc] = 1;
                q.push({nr,nc});
            }
        }

        return false;
    }
};
