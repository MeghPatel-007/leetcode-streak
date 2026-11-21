#include <bits/stdc++.h>
using namespace std;

// * minimum
class Solution
{
public:
    int minRange(int a, int b, int c)
    {
        int x = max({a, b, c}) - min({a, b, c});
        int y = max({b + c, b, c}) - min({b + c, b, c});
        int z = max({a, a + c, c}) - min({a, a + c, c});
        int w = max({a, b, a + b}) - min({a, b, a + b});
        return min({x, y, z, w});
    }
};
