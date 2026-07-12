#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int secondsBetweenTimes(string startTime, string endTime)
    {
        int n = startTime.size();
        vector<int> time1;
        vector<int> time2;
        string s, e;
        for (int i = 0; i < n; i++)
        {
            if (startTime[i] != ':')
            {
                s += startTime[i];
                e += endTime[i];
            }
            else
            {
                time1.push_back(stoi(s));
                s = "";
                time2.push_back(stoi(e));
                e = "";
            }
        }
        time1.push_back(stoi(s));
        time2.push_back(stoi(e));
        int res = (time2[0] * 3600 + time2[1] * 60 + time2[2]) - (time1[0] * 3600 + time1[1] * 60 + time1[2]);
        return res;
    }
};
