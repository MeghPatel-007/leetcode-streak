#include <bits/stdc++.h>
using namespace std;

// * bit manipulation,right shift
class Solution
{
public:
    bool checkKthBit(int n, int k)
    {
        return (n >> k) & 1 ? true : false;
    }
};
