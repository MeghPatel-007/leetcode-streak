#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void dfs(int n,string curr,vector<string>& res){
        if(curr.length() == n){
            res.push_back(curr);
            return;
        }
        for(auto ch:{'a','b','c'}){
            if(curr.length()==0||curr[curr.length()-1]!=ch){
                dfs(n,curr+ch,res);
            }
        }
    }
    string getHappyString(int n, int k) {
        string curr = "";
        vector<string> res = {};
        dfs(n,curr,res);
        if(k<=res.size()){
            return res[k-1];
        }else{
            return "";
        }
    }
};