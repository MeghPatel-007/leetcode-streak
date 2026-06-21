#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int maxCost = *max_element(costs.begin(), costs.end());

        vector<int> freq(maxCost + 1, 0);

        for (int cost : costs)
            freq[cost]++;

        int count = 0;

        for (int price = 1; price <= maxCost; price++) {
            if (freq[price] == 0)
                continue;

            int buy = min(freq[price], coins / price);

            count += buy;
            coins -= buy * price;

            if (coins < price)
                break;
        }

        return count;
    }
};
