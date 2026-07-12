#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int i,unordered_map<int,vector<int>>& adj,int v,int e,vector<bool>& visited){
        visited[i]=true;
        v++;
        e += adj[i].size();

        for(auto& ngbr : adj[i]){
            if(!visited[ngbr]){
                dfs(i,adj,v,e,visited);
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        //adjaceny list
        unordered_map<int,vector<int>>adj(n);
        for(auto& edge : edges){
            int a = edge[0];
            int b = edge[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        vector<bool>visited(n,false);
        int result = 0;
        for(int i=0;i<n;i++){
            if(visited[i]){
                continue;
            }
            int v = 0;
            int e = 0;
            dfs(i,adj,v,e,visited);
            if(v*(v-1)==e){
                result++;
            }
        }
        return result;
    }
};
