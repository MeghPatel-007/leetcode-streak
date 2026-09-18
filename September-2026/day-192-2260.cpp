#include <bits/stdc++.h>
using namespace std;

// * hash map,sliding window
class Solution
{
public:
    int minimumCardPickup(vector<int> &cards)
    {
        int n = cards.size();
        int minCards = INT_MAX;
        unordered_map<int, int> m;
        for (int i = 0; i < n; i++)
        {
            if (m.find(cards[i]) != m.end())
            {
                minCards = min(minCards, i - m[cards[i]] + 1);
            }
            m[cards[i]] = i;
        }
        return minCards == INT_MAX ? -1 : minCards;
    }
};
