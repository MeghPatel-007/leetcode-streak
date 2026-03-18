#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string s = strs[0];
        if(s=="")return s;
        for(int i=0;i<strs.size();i++){
            for(int j=0;j<=strs[i].length()&&j<s.length();j++){
                string newword = strs[i];
                if(s[j]!=newword[j]){
                    s = s.substr(0,j);
                }
            }
        }
        return s;
    }
};