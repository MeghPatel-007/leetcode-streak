#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int smallestNumber(int n, int t)
    {
        while (1)
        {
            int product = 1;
            int m = n;
            while (m)
            {
                int r = m % 10;
                product *= r;
                if (product == 0)
                    break;
                m /= 10;
            }
            if (product % t == 0)
                break;
            else
                n++;
        }
        return n;
    }
};
