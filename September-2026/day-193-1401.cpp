#include <bits/stdc++.h>
using namespace std;

// * math
class Solution
{
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2)
    {
        if (x1 == x2 || y1 == y2)
            return false;
        int nearestX = max(x1, min(xCenter, x2));
        int nearestY = max(y1, min(yCenter, y2));
        int dx = xCenter - nearestX;
        int dy = yCenter - nearestY;
        return (dx * dx + dy * dy) <= (radius * radius);
    }
};
