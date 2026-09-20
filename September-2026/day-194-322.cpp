#include <bits/stdc++.h>
using namespace std;

// * dp,recursion,tabulation
class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        vector<int> t(amount + 1, 1e9);
        t[0] = 0;
        for (int i = 1; i <= amount; i++)
        {
            for (int coin : coins)
            {
                if (i >= coin)
                {
                    t[i] = min(t[i], 1 + t[i - coin]);
                }
            }
        }
        return t[amount] >= 1e9 ? -1 : t[amount];
    }
};
