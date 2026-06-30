#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        vector<int> lastseen(3,-1);
        int cnt = 0;
        for(int i=0;i<n;i++){
            lastseen[s[i]-'a'] = i;
            if(lastseen[0] != -1 && lastseen[1] != -1 && lastseen[2] != -1 ){
                cnt += 1 + min(lastseen[0],min(lastseen[1],lastseen[2]));
            }
        }
        return cnt;
    }
};
