#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProduct(int n)
    {
        vector<int> v;
        while (n != 0)
        {
            v.push_back(n % 10);
            n /= 10;
        }
        sort(v.begin(), v.end());
        int num = v.size();
        if (num == 1)
            return v[0];
        return v[num - 1] * v[num - 2];
    }
};
