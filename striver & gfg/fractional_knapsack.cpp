#include <bits/stdc++.h>
using namespace std;

// * greedy algo
class Solution
{
public:
    double fractionalKnapsack(vector<int> &val, vector<int> &wt, int capacity)
    {
        int n = val.size();
        vector<vector<int>> items(n, vector<int>(2));
        for (int i = 0; i < n; i++)
        {
            items[i][0] = val[i];
            items[i][1] = wt[i];
        }
        sort(items.begin(), items.end(), [](vector<int> &a, vector<int> &b) -> bool
             {
            double a1 = (1.0*a[0])/a[1];
            double b1 = (1.0*b[0])/b[1];
            return a1 > b1; });
        double v = 0;
        for (int i = 0; i < n; i++)
        {
            if (capacity >= items[i][1])
            {
                capacity -= items[i][1];
                v += items[i][0];
            }
            else
            {
                v += ((double)items[i][0] / items[i][1]) * capacity;
                break;
            }
        }
        return v;
    }
};
