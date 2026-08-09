#include <bits/stdc++.h>
using namespace std;
// * two pointers
class Solution
{
public:
    double minPrice(vector<int> &prices, vector<int> &discounts)
    {
        sort(begin(prices), end(prices), greater<int>());
        sort(begin(discounts), end(discounts), greater<int>());
        int i = 0;
        int j = 0;
        int n = prices.size();
        int m = discounts.size();
        double sum = 0;
        while (i < n && j < m)
        {
            sum += prices[i] * (100 - discounts[j]) / double(100);
            i++;
            j++;
        }
        while (i < n)
        {
            sum += prices[i];
            i++;
        }
        return sum;
    }
};
