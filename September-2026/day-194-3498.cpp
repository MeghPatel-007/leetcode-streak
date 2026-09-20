#include <bits/stdc++.h>
using namespace std;

// * string
class Solution
{
public:
    int reverseDegree(string s)
    {
        int sum = 0;
        int n = s.length();
        for (int i = 0; i < n; i++)
        {
            sum += (i + 1) * ('z' - s[i] + 1);
        }
        return sum;
    }
};
