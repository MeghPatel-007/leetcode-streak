#include <bits/stdc++.h>
using namespace std;

// * array 
class Solution
{
public:
    int minRotations(string s)
    {
        int init = s[0] - '0';
        int sum = min(10 - init, init);
        for (int i = 1; i < 10; i++)
        {
            int x = s[i] - '0';
            int y = s[i - 1] - '0';
            if (x > y)
            {
                sum += min(10 - x + y, x - y);
            }
            else
            {
                sum += min(10 - y + x, y - x);
            }
        }
        return sum;
    }
};
