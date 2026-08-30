#include <bits/stdc++.h>
using namespace std;

// * brute force
class Solution
{
public:
    int elevatorRequests(int n, vector<int> &requests)
    {                                // 2,1,4,3
        int startTime = requests[0]; // 2
        int totalTime = requests[0]; // 2
        for (int i = 1; i < requests.size(); i++)
        {
            int finishedTime = abs(requests[i] - startTime); // 1,3,1
            startTime = requests[i];                         // 1,4,3
            totalTime += finishedTime;                       // 3,6,7
        }
        return totalTime;
    }
};
