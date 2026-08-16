#include <bits/stdc++.h>
using namespace std;

// * binary search on answers 
class Solution
{
public:
    int minPenalty(int period, vector<int> &lights, vector<int> &arrivalTime)
    {
        int maxLight = 0;
        for (int l : lights)
        {
            maxLight = max(maxLight, l);
        }

        int maxWait = 0;
        for (int t : arrivalTime)
        {
            int r = t % period;
            if (r >= maxLight)
            {
                maxWait = max(maxWait, period - r);
            }
        }

        return maxWait;
    }
};
