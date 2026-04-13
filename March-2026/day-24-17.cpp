#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string>ans;
    unordered_map<char, string> m = {
    {'2',"abc"}, {'3',"def"}, {'4',"ghi"}, {'5',"jkl"},
    {'6',"mno"}, {'7',"pqrs"}, {'8',"tuv"}, {'9',"wxyz"}
};

    void solve(string d,int n,string c){
        if(d.length()==n){
            ans.push_back(c);
            return;
        }
        string w = m[d[n]];
        for(char ch:w){
            c.push_back(ch);
            solve(d,n+1,c);
            c.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        string current = "";
        solve(digits,0,current);
        return ans;
    }
};