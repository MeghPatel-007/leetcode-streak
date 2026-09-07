#include <bits/stdc++.h>
using namespace std;

// * string
class Solution
{
public:
    int countRotations(string s, int k)
    {
        int n = s.length();
        s = s + s;
        int mainScore = 0;
        for (int i = 0; i < n; i++)
        {
            int score = 0;
            for (int j = i + 1; j < n + i; j++)
            {
                if (s[j - 1] == s[j])
                    score++;
            }
            if (score == k)
                mainScore++;
        }
        return mainScore;
    }
};
