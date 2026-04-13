#include <bits/stdc++.h>
using namespace std;
// memory exceed error
// class Solution {
// public:
//     int dp(int si,vector<int>f1,vector<int>f2,string& word){
//         if(si==word.length())return 0;
//         int best = INT_MAX;
//         char c = word[si];
//         int pos = c - 'A';
//         int i = pos/6,j = pos%6,d1,d2;
//         if(f1[0]==-1&&f1[1]==-1){
//             d1 = 0;
//         }else{
//             d1 = abs(f1[0]-i) + abs(f1[1]-j);
//         }
//         best = min(best,d1 + dp(si+1,{i,j},f2,word));

//         if(f2[0]==-1&&f2[1]==-1){
//             d2 = 0;
//         }else{
//             d2 = abs(f2[0]-i) + abs(f2[1]-j);
//         }
//         best = min(best,d2 + dp(si+1,f1,{i,j},word));

//         return best;
//     }
//     int minimumDistance(string word) {
//         return dp(0,{-1,-1},{-1,-1},word);
//     }
// };

class Solution
{
public:
    int memo[301][27][27];

    int dist(int a, int b)
    {
        if (a == 26)
            return 0;
        return abs(a / 6 - b / 6) + abs(a % 6 - b % 6);
    }

    int dp(int i, int f1, int f2, string &word)
    {
        if (i == word.size())
            return 0;

        if (memo[i][f1][f2] != -1)
            return memo[i][f1][f2];

        int curr = word[i] - 'A';

        int useF1 = dist(f1, curr) + dp(i + 1, curr, f2, word);
        int useF2 = dist(f2, curr) + dp(i + 1, f1, curr, word);

        return memo[i][f1][f2] = min(useF1, useF2);
    }

    int minimumDistance(string word)
    {
        memset(memo, -1, sizeof(memo));
        return dp(0, 26, 26, word);
    }
};