#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> validSequence(string word1, string word2)
    {
        int n = word1.length();
        int m = word2.length();

        vector<int> RHSMatching(n + 1, 0);
        int i = n - 1;
        int j = m - 1;
        int rightMatched = 0;
        while (i >= 0)
        {
            if (j >= 0 && word1[i] == word2[j])
            {
                rightMatched++;
                j--;
            }
            RHSMatching[i] = rightMatched;
            i--;
        }
        i = 0;
        j = 0;
        bool power = true;
        vector<int> ans;
        while (i < n && j < m)
        {
            if (word1[i] == word2[j])
            {
                ans.push_back(i);
                j++;
            }
            else if (power == true && RHSMatching[i + 1] >= m - j - 1)
            {
                ans.push_back(i);
                j++;
                power = false;
            }
            i++;
        }
        if (j == m)
            return ans;
        return {};
    }
};
