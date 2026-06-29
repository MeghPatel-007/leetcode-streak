#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numOfStrings(vector<string> &patterns, string word)
    {
        int count = 0;
        for (string p : patterns)
        {
            // if (word.contains(p))
            //     count++;
            if(word.find(p)!= string::npos)count++;
        }
        return count;
    }
};
