#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPowerOfFour(int n)
    {
        // 4^16 = 1073741824 which is in 32-bit range
        // 2^31-1 = 2147483647
        if (n <= 0)
            return false;
        while (n % 4 == 0)
        {
            n /= 4;
        }
        return n == 1 ? true : false;
    }
};
// lC: tc => O(1)
// class Solution {
// public:
//     bool isPowerOfFour(int n) {
//         if(n<1) return false;
//         while(n>1){
//             if(n%4 != 0) return false;
//             n = n/4;
//         }
//     return true;
//     }
// };
