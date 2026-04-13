#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int f = 0;
        int len = height.size() - 1;
        int l = len;
        int area = 0;
        while (abs(f - l) != 0)
        {
            int curr_aera = len * (min(height[f], height[l]));
            if (area < curr_aera)
                area = curr_aera;
            if (height[f] >= height[l])
            {
                l--;
            }
            else
            {
                f++;
            }
            len--;
        }
        return area;
    }
};