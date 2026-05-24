#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxJumps(vector<int> &arr, int d)
    {
        int n = arr.size();
        vector<int> t(n + 1, -1);
        vector<pair<int, int>> vec;
        for (int i = 0; i < n; i++)
        {
            vec.push_back({arr[i], i});
        }
        sort(vec.begin(), vec.end());
        for (auto &it : vec)
        {
            int val = it.first;
            int i = it.second;
            int result = 1;
            for (int j = i - 1; j >= max(0, i - d); j--)
            {
                if (arr[j] >= arr[i])
                    break;
                result = max(result, 1 + t[j]);
            }
            for (int j = i + 1; j <= min(n - 1, i + d); j++)
            {
                if (arr[j] >= arr[i])
                    break;
                result = max(result, 1 + t[j]);
            }
            t[i] = result;
        }
        int answer = 1;
        for (int i = 0; i < n; i++)
        {
            answer = max(answer, t[i]);
        }
        return answer;
    }
};
