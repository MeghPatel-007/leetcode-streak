#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &v1, vector<int> &v2)
    {
        vector<int> result;
        merge(v1.begin(), v1.end(), v2.begin(), v2.end(), back_inserter(result));
        if (result.size() % 2 != 0)
        {
            int idx = result.size() / 2;
            return result[idx];
        }
        else
        {
            int idx1 = result.size() / 2 - 1;
            int idx2 = (result.size() / 2);
            return (result[idx1] + result[idx2]) / double(2);
        }
    }
};