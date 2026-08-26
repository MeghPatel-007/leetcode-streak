#include <bits/stdc++.h>
using namespace std;

// * String , stringstream
class Solution
{
public:
    string reverseWords(string s)
    {
        vector<string> words;
        stringstream ss(s);
        string word;
        string res;
        int n = s.length();
        while (ss >> word)
        {
            words.push_back(word);
        }
        reverse(begin(words), end(words));
        for (int i = 0; i < words.size(); i++)
        {
            res += words[i];
            if (i != words.size() - 1)
                res += " ";
        }
        return res;
    }
};
