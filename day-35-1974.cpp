#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minTimeToType(string word)
    {
        int counter = 0;
        char curr = 'a';
        for (char w : word)
        {
            int ans = abs(w - curr);
            if (ans > 13)
                ans = 26 - ans;
            if (ans != 0)
                counter += ans;
            counter++;
            curr = w;
        }
        return counter;
    }
};