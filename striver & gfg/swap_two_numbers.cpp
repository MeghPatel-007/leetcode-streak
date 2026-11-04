#include <bits/stdc++.h>
using namespace std;

// * bit manipulation,xor operator
int main()
{
    int a, b;
    cin >> a >> b;

    // code here
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;

    cout << a << " " << b;
    return 0;
}
