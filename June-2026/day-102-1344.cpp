#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double angleClock(int hour, int minutes)
    {
        if (hour == 12)
            hour = 0;
        double val = abs(minutes * 6 - 30 * (hour + double(minutes) / 60));
        return min(val, 360 - val);
    }
};
