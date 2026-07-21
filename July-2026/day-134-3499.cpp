#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.length();
        int activeCount = count(s.begin(),s.end(),'1');
        int i = 0;
        vector<int>inactiveCount;
        while(i<n){
            if(s[i] == '0'){
                int start = i;
                while(i<n&&s[i]=='0')i++;
                inactiveCount.push_back(i-start);
            }else{
                i++;
            }
        }
        int m = inactiveCount.size();
        int mx = 0;
        for(int i=1;i<m;i++){
            mx = max(mx,inactiveCount[i-1]+inactiveCount[i]);
        }
        return mx+activeCount;
    }
};
