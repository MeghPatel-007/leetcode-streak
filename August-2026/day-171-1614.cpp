#include<bits/stdc++.h>
using namespace std;

// * string
class Solution {
public:
    int maxDepth(string s) {
        int mx = 0;
        int depth = 0;
        for(char ch:s){
            if(ch == '(')depth++;
            else if(ch == ')')depth--;
            mx = max(mx,depth);
        }
        return mx;
    }
};
