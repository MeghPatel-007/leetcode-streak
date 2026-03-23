#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        int j = 0, x;
        if (haystack.length() < needle.length())
        {
            return -1;
        }
        for (int i = 0; i < haystack.length(); i++)
        {
            if (needle[j] == haystack[i])
            {
                if (j == 0)
                    x = i;
                j++;
                if (j == needle.length())
                {
                    return x;
                }
            }
            else
            {
                if (j > 0)
                    i = x;
                x = -1;
                j = 0;
            }
        }
        return -1;
    }
};