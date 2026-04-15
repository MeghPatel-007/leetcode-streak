#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int minn = INT_MAX;
        for (int i = 0; i < words.size(); i++)
        {
            if (words[i] == target){
                minn = min({minn, abs(i - startIndex),int(words.size())-abs(i - startIndex)});

            }
            if (minn == 0)
                return 0;
        }
        return minn==INT_MAX?-1:minn;
    }
};