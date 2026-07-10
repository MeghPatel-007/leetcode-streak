#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rows;
    int cols;
    vector<vector<int>> anTb;
    int customUpperBound(vector<pair<int,int>>& arr,int t){
        int n = arr.size();
        int l = 0;
        int r = n-1;
        int res = 0;

        while(l <= r){
            int mid = l + (r-l)/2;
            if(arr[mid].first <= t){
                res = mid;
                l = mid+1;
            }else{
                r = mid-1;
            }
        }
        return res;
    }
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<pair<int,int>>arr(n);
        for(int i=0;i<n;i++){
            arr[i] = {nums[i],i};
        }

        sort(arr.begin(),arr.end());
        vector<int> nodeToIdx(n);
        for(int i=0;i<n;i++){
            int node = arr[i].second;
            nodeToIdx[node] = i;
        }
        rows = n;
        cols = log2(n)+1;

        anTb.resize(rows,vector<int>(cols,0));

        //fill 0th col first;
        for(int node=0;node<n;node++){
            int farthestIdxOneHop = customUpperBound(arr,arr[node].first+maxDiff);
            anTb[node][0] = farthestIdxOneHop;
        }

        //fill remaining cols;
        for(int j=1;j<cols;j++){
            for(int node=0;node<n;node++){
                anTb[node][j] = anTb[anTb[node][j-1]][j-1];
            }
        }

        vector<int>res;
        for(auto& query:queries){
            int u = query[0];
            int v = query[1];

            int a = nodeToIdx[u];
            int b = nodeToIdx[v];

            if(a == b){
                res.push_back(0);
                continue;
            }
            if(a>b){
                swap(a,b);
            }
            int curr = a;
            int jmps = 0;

            for(int j=cols-1;j>=0;j--){
                if(anTb[curr][j] < b){
                    curr = anTb[curr][j];
                    jmps += (1 << j);
                }
            }
            if(anTb[curr][0] >= b){
                res.push_back(jmps+1);
            }else{
                res.push_back(-1);
            }
        }
        return res;
    }
};
