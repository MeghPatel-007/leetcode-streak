#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int MOD = 1e9 + 7;
    typedef long long ll;
    vector<int> sumAndMultiply(string s, vector<vector<int>> &queries)
    {
        vector<int> answer(queries.size());
        int n = s.length();
        vector<int> digitSumUpTo(n, 0);
        vector<ll> numberupto(n, 0);
        vector<ll> nonZeroNumber(n, 0);
        vector<ll> pow10(n + 1, 0);
        pow10[0] = 1;
        nonZeroNumber[0] = (s[0] != '0') ? 1 : 0;
        numberupto[0] = s[0] - '0';
        digitSumUpTo[0] = s[0] - '0';
        for (int i = 1; i <= n; i++)
        {
            pow10[i] = (pow10[i - 1] * 10) % MOD;
        }
        for (int i = 1; i < n; i++)
        {
            int digit = s[i] - '0';
            nonZeroNumber[i] = nonZeroNumber[i - 1] + ((digit != 0) ? 1 : 0);
        }
        for (int i = 1; i < n; i++)
        {
            digitSumUpTo[i] = digitSumUpTo[i - 1] + s[i] - '0';
            if (s[i] != '0')
            {
                numberupto[i] = (numberupto[i - 1] * 10 + s[i] - '0') % MOD;
            }
            else
            {
                numberupto[i] = numberupto[i - 1];
            }
        }

        for (int i = 0; i < queries.size(); i++)
        {
            int l = queries[i][0];
            int r = queries[i][1];
            int k = nonZeroNumber[r] - ((l == 0) ? 0 : nonZeroNumber[l - 1]);
            int numBefore = (l == 0) ? 0 : numberupto[l - 1];
            ll sum = digitSumUpTo[r] - ((l == 0) ? 0 : digitSumUpTo[l - 1]);
            ll x = (numberupto[r] - (numBefore * pow10[k] % MOD) + MOD) % MOD;
            answer[i] = (int)((x * sum) % MOD);
        }
        return answer;
    }
};
