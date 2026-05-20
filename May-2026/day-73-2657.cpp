#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findThePrefixCommonArray(vector<int> &A, vector<int> &B)
    {
        unordered_map<int, int> m;
        vector<int> answer(A.size());
        int num = 0;
        for (int i = 0; i < A.size(); i++)
        {
            m[A[i]]++;
            m[B[i]]++;
            if (m[A[i]] == 2)
            {
                num++;
            }
            if (m[B[i]] == 2)
            {
                num++;
            }
            if (A[i] == B[i])
                num--;
            answer[i] = num;
        }
        return answer;
    }
};
