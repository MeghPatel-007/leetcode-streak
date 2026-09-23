#include <bits/stdc++.h>
using namespace std;

// class Solution {
// public:
//     int solve(int num){
//         int sum = 0;
//         while(num != 0){
//             sum += num%10;
//             num /= 10;
//         }
//         return sum;
//     }
//     int addDigits(int num) {
//         while(num >= 10){
//             num = solve(num);
//         }
//         return num;
//     }
// };

// Digital root
class Solution
{
public:
    int addDigits(int num)
    {
        if (num == 0)
            return 0;
        return 1 + ((num - 1) % 9);
    }
};
