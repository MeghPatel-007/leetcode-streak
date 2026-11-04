#include <bits/stdc++.h>
using namespace std;

int solution1(int &n, int &power)
{
    int ans = 0;
    for (int i = 0; pow(i, power) <= n; i++)
    {
        ans = i;
    }
    return ans;
}
int solution2(int &n, int &power)
{
    if (n > 2)
        return n;
    int l = 0;
    int r = n / 2;
    int ans = 0;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (power << mid <= n)
        {
            ans = mid;
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    return ans;
}

int main()
{
    // testcase-1
    int n = 10234;
    int power = 3;
    cout << solution1(n, power) << endl;
    ;
    cout << solution2(n, power);
    return 0;
}
