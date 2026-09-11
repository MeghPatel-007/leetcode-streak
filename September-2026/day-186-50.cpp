#include<bits/stdc++.h>
using namespace std;

// * binary exponentiation
class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.0;
        long long nn = n * 1LL;
        if(nn < 0)nn = -1*nn;
        while(nn > 0){
            if(nn % 2 == 1){
                ans *= x;
                nn--;
            }else{
                x *= x;
                nn /= 2;
            }
        }
        if(n < 0)ans = double(1.0)/double(ans);
        return ans;
    }
};
