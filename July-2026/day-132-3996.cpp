#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // manhatten dist
    bool canReach(vector<int> &start, vector<int> &target)
    {
        int startSum = start[0] + start[1];
        int targetSum = target[0] + target[1];
        return (targetSum - startSum) % 2 == 0 ? true : false;
    }
};
