#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        //brute force but log(n^2)
        // vector<int>answer(queries.size(),-1);
        // for(int i=0;i<queries.size();i++){
        //     int mini = INT_MAX;
        //     for(int j=0;j<nums.size();j++){
        //         if(nums[j]==nums[queries[i]]&&j!=queries[i]){
        //             mini = min({mini,abs(queries[i]-j),int(nums.size())-abs(queries[i]-j)});
        //         }
        //     }
        //     mini==INT_MAX?answer[i]=-1:answer[i]=mini;
        // }
        // return answer;
    // map<int,vector<int>>m;
    // vector<int>answer;
    // for(int i=0;i<nums.size();i++){
    //     m[nums[i]].push_back(i);
    // }
    // for(auto q : queries){
    //     vector<int>& temp = m[nums[q]];
    //     cout <<"h"<< temp.size() << endl;
    //     if(temp.size()==1){
    //         answer.push_back(-1);
    //         continue;
    //     }
    //     int idx = lower_bound(temp.begin(), temp.end(), q) - temp.begin();
    //    int n = nums.size();
    // int left = (idx - 1 + temp.size()) % temp.size();
    // int right = (idx + 1) % temp.size();

    // int d1 = abs(temp[idx] - temp[left]);
    // int d2 = abs(temp[idx] - temp[right]);

    // int mini = min({min(d1, n - d1), min(d2, n - d2)});

    // answer.push_back(mini);
    // }
    // return answer;
    const int n = nums.size();
    vector<int> ans;
    // minDist[i] := the minimum distance between nums[i], and any other index j
    // in the circular array, where nums[j] == nums[i]
    vector<int> minDist(n, n);
    unordered_map<int, int> lastSeen;

    for (int i = 0; i < n * 2; ++i) {
      const int index = i % n;
      const int num = nums[index];
      if (const auto it = lastSeen.find(num); it != lastSeen.cend()) {
        const int prevIndex = it->second % n;
        const int d = i - prevIndex;
        minDist[index] = min(minDist[index], d);
        minDist[prevIndex] = min(minDist[prevIndex], d);
      }
      lastSeen[num] = i;
    }

    for (const int query : queries)
      ans.push_back(minDist[query] == n ? -1 : minDist[query]);

    return ans;
    }
};
