#include <bits/stdc++.h>
using namespace std;

// class Solution {
// public:
//     bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
//         bool flag = true;
//         long long currmass = mass;
//         sort(asteroids.begin(),asteroids.end());
//         for(int& asteroid:asteroids){
//             if(currmass < asteroid){
//                 flag = false;
//                 break;
//             }
//             currmass += asteroid;
//         }
//         return flag;
//     }
// };

class Solution
{
public:
    bool asteroidsDestroyed(int mass, vector<int> &asteroids)
    {
        int n = asteroids.size();
        long long int curmass = mass, count = 0;
        for (int i = 0; i < n; i++)
        {
            if (curmass >= asteroids[i])
            {
                curmass += asteroids[i];
                asteroids[i] = 0;
            }
            else
                count += 1;
        }
        while (count > 0)
        {
            int temp = 0;
            for (int i = 0; i < n; i++)
            {
                if (curmass >= asteroids[i])
                {
                    curmass += asteroids[i];
                    asteroids[i] = 0;
                }
                else
                    temp += 1;
            }
            if (count == temp)
                return false;
            count = temp;
        }
        return true;
    }
};
