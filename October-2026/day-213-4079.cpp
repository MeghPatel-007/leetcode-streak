#include <bits/stdc++.h>
using namespace std;

// * sieve of eratosthenes
class Solution
{
public:
    vector<int> maxPrimes(int n, int s)
    {
        vector<bool> isPrime(n + 1, true);
        isPrime[0] = false;
        if (n >= 1)
            isPrime[1] = false;
        for (long long i = 2; i * i <= n; i++)
            if (isPrime[i])
                for (long long j = i * i; j <= n; j += i)
                    isPrime[j] = false;

        vector<int> res;
        long long total = 0;
        for (int p = 2; p <= n; p++)
        {
            if (!isPrime[p])
                continue;
            if (total + p > s)
                break;
            total += p;
            res.push_back(p);
        }
        return res;
    }
};
