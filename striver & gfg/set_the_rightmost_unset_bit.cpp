#include <bits/stdc++.h>
using namespace std;

// * bit manipulation,or operator
class Solution
{
public:
    int setBit(int n)
    {
        return n | n + 1;
    }
};
