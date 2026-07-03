#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    typedef long long ll;
    typedef pair<long long,int> p;
    bool check(int mid,int n,ll k,unordered_map<int , vector<vector<int>>> &adj ){
        // result[i] = min cost path from src to ith node;
        vector<ll> result(n,LLONG_MAX);

        //min-heap for dijkstra's
        priority_queue<p, vector<p>,greater<p>> pq;

        result[0] = 0;
        pq.push({0,0});

        while(!pq.empty()){
            ll d = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if(d > k){
                return false;
            }

            // if total cost is reaching the source from to ith = d
            if(d > result[node])continue;

            if(node == n-1)return true;
            for(auto &ngbr : adj[node]){
                int v = ngbr[0];
                int cost = ngbr[1];
                if(cost < mid)continue;
                if(d + cost < result[v]){
                    result[v] = d+cost;
                    pq.push({d+cost,v});
                }
            }
        }
        return false;
    }

    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
       int n = online.size();

       //adjancey list
       //u -> {(v,cost),{v',cost'}}
        unordered_map<int , vector<vector<int>>> adj;
        int l = INT_MAX;
        int r = 0;
        for(auto& edge : edges){
            int u = edge[0];
            int v = edge[1];
            int cost = edge[2];

            if(!online[u]||!online[v]){
                continue;
            }
            adj[u].push_back({v,cost});
            l = min(l,cost);
            r = max(r,cost);
       }

        int ans = -1;

        while(l <= r){
            int mid = l + (r-l)/2;
            if(check(mid,n,k,adj)) {ans = mid;l = mid + 1;}
            else r = mid - 1;
        }

        return ans;
    }
};
