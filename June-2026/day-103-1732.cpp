#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int largestAltitude(vector<int> &gain)
    {
        int maxi = 0;
        int sum = 0;
        for (int i : gain)
        {
            maxi = max(maxi, sum += i);
        }
        return maxi;
    }
};
