#include <bits/stdc++.h>
using namespace std;

// class Solution {
// public:
//     int getMinDistance(vector<int>& nums, int target, int start) {
//         int i=start;
//         int c = 0;
//         bool flag = true;
//         int val = INT_MAX;
//         while(c!=nums.size()){
//             if(target==nums[i]){
//                 val = min(val,abs(i-start));
//             }
//             if(i==nums.size()-1){
//                 i=start;
//                 flag=false;
//             }
//             if(flag == true) i++;
//             else i--;
//             c++;
//         }
//         return val;
//     }
// };

class Solution
{
public:
    int getMinDistance(vector<int> &nums, int target, int start)
    {
        int minn = INT_MAX;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == target)
                minn = min(minn, abs(i - start));
            if (minn == 0)
                return 0;
        }

        return minn;
    }
};