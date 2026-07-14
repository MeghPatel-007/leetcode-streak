// * Dp

// #include <bits/stdc++.h>
// using namespace std;

// class Solution
// {
// public:
//     int t[201][201][201];
//     int MOD = 1e9+7;
//     //nums = {200,200,200};
//     // first = {200,200} => 200;
//     // second = {200} => 200;
//     int solve(vector<int> &nums, int i, int first, int second)
//     {
//         if (i == nums.size())
//         {
//             bool bothNonEmpty = (first != 0 && second != 0);
//             bool gcdMatch = (first == second);
//             return (bothNonEmpty && gcdMatch) ? 1 : 0;
//         }

//         //memoization

//         if(t[i][first][second] != -1){
//             return t[i][first][second];
//         }

//         int skip = solve(nums, i + 1, first, second);
//         int take1 = solve(nums, i + 1, __gcd(first, nums[i]), second);
//         int take2 = solve(nums, i + 1, first, __gcd(second, nums[i]));

//         return t[i][first][second] = (0LL + skip + take1 + take2) % MOD;
//     }
//     int subsequencePairCount(vector<int> &nums)
//     {
//         return solve(nums, 0, 0, 0);
//     }
// };

// * bottom-up + dp

// #include <bits/stdc++.h>
// using namespace std;

// class Solution
// {
// public:
//     int MOD = 1e9 + 7;
//     int subsequencePairCount(vector<int> &nums)
//     {
//         int n = nums.size();
//         int maxEl = *max_element(nums.begin(),nums.end());
//         int t[n+1][maxEl+1][maxEl+1];

//         for(int first=0;first <= maxEl;first++){
//             for(int second=0;second <= maxEl;second++){
//                 bool bothNonEmpty = (first != 0 && second != 0);
//                 bool gcdMatch = (first == second);
//                 t[n][first][second] = (bothNonEmpty && gcdMatch) ? 1 : 0;
//             }
//         }

//         for(int i=n-1;i>=0;i--){
//             for(int first=maxEl;first>=0;first--){
//                 for(int second=maxEl;second>=0;second--){
//                     int skip = t[i+1][first][second];
//                     int take1 = t[i+1][__gcd(first,nums[i])][second];
//                     int take2 = t[i+1][first][__gcd(second,nums[i])];

//                     t[i][first][second] = (0LL + skip + take1 + take2)%MOD;

//                 }
//             }
//         }
//         return t[0][0][0];
//     }
// };

// * optimal soln

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int MOD = 1e9 + 7;
    int subsequencePairCount(vector<int> &nums)
    {
        int n = nums.size();
        int maxEl = *max_element(nums.begin(), nums.end());
        vector<vector<int>> prev(maxEl + 1, vector<int>(maxEl + 1, 0));
        for (int first = 0; first <= maxEl; first++)
        {
            for (int second = 0; second <= maxEl; second++)
            {
                bool bothNonEmpty = (first != 0 && second != 0);
                bool gcdMatch = (first == second);
                prev[first][second] = (bothNonEmpty && gcdMatch) ? 1 : 0;
            }
        }

        for (int i = n - 1; i >= 0; i--)
        {
            vector<vector<int>> curr(maxEl + 1, vector<int>(maxEl + 1, 0));
            for (int first = maxEl; first >= 0; first--)
            {
                for (int second = maxEl; second >= 0; second--)
                {
                    int skip = prev[first][second];
                    int take1 = prev[__gcd(first, nums[i])][second];
                    int take2 = prev[first][__gcd(second, nums[i])];

                    curr[first][second] = (0LL + skip + take1 + take2) % MOD;
                }
            }
            prev = move(curr);
        }
        return prev[0][0];
    }
};
