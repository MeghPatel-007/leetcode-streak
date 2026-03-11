#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0)return 1;
        int mask = 0;
        int y = n;
        while(y){
    mask = (mask << 1) | 1;
            y=y>>1;
        }
        int x = mask&(~n);
        return x;
    }
};