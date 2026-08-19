#include <bits/stdc++.h>
using namespace std;

// * hash map && greedy
class Solution
{
public:
    bool isAvaliable(int num, unordered_set<int> &reserved)
    {
        return reserved.find(num) == reserved.end();
    }
    int maxNumberOfFamilies(int n, vector<vector<int>> &reservedSeats)
    {
        int m = reservedSeats.size();
        unordered_map<int, unordered_set<int>> map;
        for (int i = 0; i < m; i++)
        {
            map[reservedSeats[i][0]].insert(reservedSeats[i][1]);
        }
        int result = 0;
        if (n != map.size())
        {
            result += (n - map.size()) * 2;
        }
        for (auto &[key, val] : map)
        {
            bool grpA = isAvaliable(2, val) && isAvaliable(3, val) && isAvaliable(4, val) && isAvaliable(5, val);
            bool grpB = isAvaliable(4, val) && isAvaliable(5, val) && isAvaliable(6, val) && isAvaliable(7, val);
            bool grpC = isAvaliable(6, val) && isAvaliable(7, val) && isAvaliable(8, val) && isAvaliable(9, val);
            if (grpA && grpC)
                result += 2;
            else if (grpA || grpB || grpC)
                result++;
        }
        return result;
    }
};
