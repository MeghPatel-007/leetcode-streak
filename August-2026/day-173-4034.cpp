#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minBishopMoves(vector<int> &source, vector<int> &target)
    {
        int srcBlk = 1;
        int tarBlk = 1;
        if ((source[0] % 2 == 0 && source[1] % 2 == 0) || (source[0] % 2 == 1 && source[1] % 2 == 1))
        {
            srcBlk = 0;
        }
        if ((target[0] % 2 == 0 && target[1] % 2 == 0) || (target[0] % 2 == 1 && target[1] % 2 == 1))
        {
            tarBlk = 0;
        }
        if (srcBlk != tarBlk)
        {
            return -1;
        }
        if (abs(source[0] - target[0]) == abs(source[1] - target[1]))
            return 1;
        return 2;
    }
};
