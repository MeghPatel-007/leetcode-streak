#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string mapWordWeights(vector<string> &words, vector<int> &weights)
    {
        string result;
        for (string word : words)
        {
            int sum = 0;
            for (char ch : word)
            {
                sum += weights[ch - 'a'];
            }
            result += 'z' - sum % 26;
        }
        return result;
    }
};
