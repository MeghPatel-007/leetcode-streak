#include <bits/stdc++.h>
using namespace std;


class Solution
{
    public:
    int largestInteger(int n, int s)
    {
        int num = pow(10, n);
        for (int i = 0; i < num; i++)
        {
            int digit = num - i - 1;
            int digit2 = digit;
            int sum = 0;
            while (digit)
            {
                int r = digit % 10;
                sum += r;
                digit /= 10;
            }
            if (s == sum)
            return digit2;
        }
        return -1;
    }
};

// * improved soln
// class Solution {
// public:
//     int largestInteger(int n, int s) {
//         if (9 * n < s) {
//             return -1;
//         }

//         if (s == 0) {
//             return 0;
//         }

//         string str = "";

//         for (int i = 0; i < n; i++) {
//             int d = min(9, s);
//             str += char('0' + d);
//             s -= d;
//         }

//         return stoi(str);
//     }
// };
