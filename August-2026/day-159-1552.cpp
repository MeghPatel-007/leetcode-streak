#include <bits/stdc++.h>
using namespace std;

// * binary serach on answer min(max)
class Solution
{
public:
    bool minMagForce(vector<int> &position, int expBalls, int force, int &n)
    {
        int balls = 1;
        int j = 0;
        for (int i = 1; i < n; i++)
        {
            if (position[i] - position[j] >= force)
            {
                balls++;
                j = i;
            }
        }
        return balls >= expBalls;
    }
    int maxDistance(vector<int> &position, int m)
    {
        sort(begin(position), end(position));
        int n = position.size();
        int l = 1;
        int r = position[n - 1] - position[0];
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (minMagForce(position, m, mid, n))
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        return r;
    }
};
