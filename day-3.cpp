#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int reverse(int x) {
        long int newx=0;
        while(x != 0){
            long int r=x%10;
            newx=newx*10+r;
             if(newx > INT_MAX || newx < INT_MIN)
                return 0;
            x/=10;
        }
        return newx;
    }
};