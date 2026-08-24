#include <bits/stdc++.h>
using namespace std;

// * bit manipulation
class Solution
{
public:
    bool isPalindromic(string s)
    {
        string bin = "";
        for (auto &c : s)
        {
            bin += bitset<8>(c).to_string();
        }
        string ogBin = bin;
        reverse(bin.begin(), bin.end());
        if (bin == ogBin)
            return true;
        return false;
    }
};
