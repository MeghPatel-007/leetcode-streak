#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long nCr(int n, int r, int k)
    {
        if (r < 0 || r > n)
            return 0;
        r = min(r, n - r);
        long long res = 1;
        for (int i = 1; i <= r; i++)
        {
            res = res * (n - r + i) / i;
            if (res >= k)
                return k;
        }
        return res;
    }

    long long countPermutations(const vector<int> &cnt, int k)
    {
        long long ways = 1;
        int letters = 0;
        for (int c = 0; c < 26; c++)
        {
            letters += cnt[c];
        }

        for (int c = 0; c < 26; c++)
        {
            if (cnt[c] > 0)
            {
                ways *= nCr(letters, cnt[c], k);
                letters -= cnt[c];
            }
            if (ways >= k)
                return k;
        }
        return ways;
    }

    string smallestPalindrome(string s, int k)
    {
        int n = s.length();
        vector<int> cnt(26, 0);

        for (char c : s)
        {
            cnt[c - 'a']++;
        }

        char mid = ' ';
        if (n % 2 == 1)
        {
            for (int i = 0; i < 26; i++)
            {
                if (cnt[i] % 2 == 1)
                {
                    mid = 'a' + i;
                    break;
                }
            }
        }

        for (int i = 0; i < 26; i++)
        {
            cnt[i] /= 2;
        }

        if (countPermutations(cnt, k) < k)
        {
            return "";
        }

        string halfResult = "";
        int half = n / 2;

        for (int i = 0; i < half; i++)
        {
            for (int j = 0; j < 26; j++)
            {
                if (cnt[j] > 0)
                {
                    cnt[j]--;

                    long long ways = countPermutations(cnt, k);

                    if (ways >= k)
                    {
                        halfResult.push_back(j + 'a');
                        break;
                    }

                    k -= ways;
                    cnt[j]++;
                }
            }
        }

        string rev = halfResult;
        reverse(rev.begin(), rev.end());

        if (mid != ' ')
        {
            halfResult.push_back(mid);
        }

        return halfResult + rev;
    }
};
