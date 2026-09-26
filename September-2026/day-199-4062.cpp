#include <bits/stdc++.h>
using namespace std;

// * array
class Solution
{
public:
    bool canTransform(vector<int> &source, vector<int> &target)
    {
        long long srcSum = 0;
        long long tarSum = 0;
        for (auto s : source)
            srcSum += s;
        for (auto s : target)
            tarSum += s;
        return srcSum == tarSum;
    }
};
