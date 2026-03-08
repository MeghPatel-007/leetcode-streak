#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string check(set<int> n, int size)
    {
        int c = 0;
        for (int i = 0; i < (1 << size); i++)
        {
            if (!n.count(i))
            {
                c = i;
                break;
            }
        }
        bitset<16> b1(c);
        string res = b1.to_string();
        return res.substr(16 - size);
    }
    string findDifferentBinaryString(vector<string> &nums)
    {
        set<int> n;
        for (string i : nums)
        {
            int x = stoi(i, nullptr, 2);
            n.insert(x);
        }
        string res = check(n, nums[0].size());
        return res;
    }
};