#include <bits/stdc++.h>
using namespace std;

// * binary search on answers tc => O(nlogn);
class Solution
{
public:
    bool check_day(int day, vector<int> &bloomDay, int m, int k)
    {
        int n = bloomDay.size();
        int k1 = k;
        for (int i = 0; i < n; i++)
        {
            if (bloomDay[i] <= day)
            {
                k1--;
            }
            else
            {
                k1 = k;
            }
            if (k1 == 0)
            {
                m--;
                k1 = k;
            }
            if (m == 0)
            {
                return true;
            }
        }
        return false;
    }
    // striver
    //  bool check_day(int day,vector<int>& bloomDay,int m,int k){
    //      int n = bloomDay.size();
    //      int flowers = 0;
    //      int bouquets = 0;
    //      for(int i=0;i<n;i++){
    //          if(bloomDay[i] <= day){
    //              flowers++;
    //              if(flowers == k){
    //                  bouquets++;
    //                  flowers=0;
    //              }
    //          }else{
    //            flowers=0;
    //          }
    //      }
    //      return bouquets >= m;
    //  }
    int minDays(vector<int> &bloomDay, int m, int k)
    {
        int n = bloomDay.size();
        long long total = 1LL * k * m;
        if (total > n)
            return -1;
        int l = *min_element(begin(bloomDay), end(bloomDay));
        int r = *max_element(begin(bloomDay), end(bloomDay));
        int ans = 0;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (check_day(mid, bloomDay, m, k))
            {
                ans = mid;
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        return ans;
    }
};
