#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1)return s;
        int curr=0;
        bool goingdown = false;
        int val = min((int)s.length(),numRows);
        vector<string>rows(val);
        for(char c:s){
            rows[curr]+=c;
            if(curr==0||curr==numRows-1){
                goingdown = !goingdown;
            }
            curr += goingdown?1:-1;
        }
        string res = "";
        for(auto row:rows){
            res+=row;
        }
        return res;
    }
};