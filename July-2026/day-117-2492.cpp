#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    typedef long long ll;
    int minScore(int n, vector<vector<int>>& roads) {
        // adjaceny matrix;
        vector<vector<pair<int,int>>>adj(n+1);

        for(auto& road:roads){
            int u = road[0];
            int v = road[1];
            int dist = road[2];
            adj[u].push_back({v,dist});
            adj[v].push_back({u,dist});
        }

        queue<int>pq;
        vector<bool> visited (n+1,false);
        visited[1] = true;
        pq.push(1);
        int min_dist = INT_MAX;
        while(!pq.empty()){
            int node = pq.front();
            pq.pop();
            for(auto& [v,d]: adj[node]){
                min_dist = min(min_dist,d);
                if(!visited[v]){
                    visited[v]=true;
                    pq.push(v);
                }
            }
        }
        return min_dist;
    }
};
