#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    typedef long long ll;

    string freeSlotsFiller(ll req, int length)
    {
        string str;
        for (int d = 9; d >= 2; d--)
        {
            while (req % d == 0)
            {
                str.push_back(d + '0');
                req /= d;
            }
        }
        while (str.length() < length)
            str.push_back('1');
        reverse(str.begin(), str.end());
        return str;
    }

    string smallestNumber(string num, long long t)
    {
        int n = num.length();
        ll temp = t;
        for (int primeFactor : {2, 3, 5, 7})
        {
            while (temp % primeFactor == 0)
            {
                temp /= primeFactor;
            }
        }

        if (temp != 1)
            return "-1";
        // precompute remaining factor for the suffix
        vector<ll> remainingFactor(n + 1, t);
        for (int i = 0; i < n; i++)
        {
            int digit = num[i] - '0';

            if (digit == 0)
            {
                break;
            }

            remainingFactor[i + 1] = remainingFactor[i] / gcd(remainingFactor[i], (ll)digit);
        }

        if (remainingFactor[n] == 1)
        {
            return num;
        }

        int zeroPos = num.find('0');
        int zeroIdx = n - 1;
        if (zeroPos != -1)
        {
            zeroIdx = zeroPos;
        }

        for (int i = zeroIdx; i >= 0; i--)
        {
            ll required = remainingFactor[i];
            int freeSlots = n - i - 1;
            a for (int d = (num[i] - '0') + 1; d <= 9; d++)
            {
                ll furtherRequired = required / gcd(required, d);
                string requiredNumber = freeSlotsFiller(furtherRequired, freeSlots);

                if (requiredNumber.length() == freeSlots)
                {
                    return num.substr(0, i) + char(d + '0') + requiredNumber;
                }
            }
        }
        return freeSlotsFiller(t, n + 1);
    }
};
