#include <bits/stdc++.h>
using namespace std;

// class Solution {
// public:
// string addBinary(string a, string b) {
//     string result = "";
//     int i = a.size() - 1;
//     int j = b.size() - 1;
//     int carry = 0;

//     while (i >= 0 || j >= 0 || carry) {
//         int sum = carry;

//         if (i >= 0) sum += a[i--] - '0';
//         if (j >= 0) sum += b[j--] - '0';

//         result += (sum % 2) + '0';
//         carry = sum / 2;
//     }

//     reverse(result.begin(), result.end());
//     return result;
// }
// };

class Solution
{
public:
    string addBinary(string a, string b)
    {
        int i = a.size() - 1;
        int j = b.size() - 1;
        int dop = 0;
        string out = "";
        while (i >= 0 || j >= 0)
        {
            if (i < 0 && j >= 0)
            {
                while (j >= 0)
                {
                    if (b[j] == '1')
                    {
                        if (dop == 0)
                        {
                            out += "1";
                        }
                        else
                        {
                            out += "0";
                        }
                    }
                    else
                    {
                        if (dop == 0)
                        {
                            out += "0";
                        }
                        else
                        {
                            out += "1";
                            dop = 0;
                        }
                    }
                    --j;
                }
                break;
            }
            if (j < 0 && i >= 0)
            {
                while (i >= 0)
                {
                    if (a[i] == '1')
                    {
                        if (dop == 0)
                        {
                            out += "1";
                        }
                        else
                        {
                            out += "0";
                        }
                    }
                    else
                    {
                        if (dop == 0)
                        {
                            out += "0";
                        }
                        else
                        {
                            out += "1";
                            dop = 0;
                        }
                    }
                    --i;
                }
                break;
            }

            if (a[i] == '0')
            {
                if (b[j] == '0')
                {
                    if (dop == 0)
                    {
                        out += "0";
                    }
                    else
                    {
                        out += "1";
                        dop = 0;
                    }
                }
                else
                {
                    if (dop == 0)
                    {
                        out += "1";
                    }
                    else
                    {
                        out += "0";
                        dop = 1;
                    }
                }
            }
            else if (a[i] == '1')
            {
                if (b[j] == '0')
                {
                    if (dop == 0)
                    {
                        out += "1";
                    }
                    else
                    {
                        out += "0";
                        dop = 1;
                    }
                }
                else
                {
                    if (dop == 0)
                    {
                        out += "0";
                        dop = 1;
                    }
                    else
                    {
                        out += "1";
                        dop = 1;
                    }
                }
            }
            --i;
            --j;
        }
        if (dop)
            out += "1";
        string outRev = "";
        for (int i = out.size() - 1; i >= 0; --i)
        {
            outRev += out[i];
        }
        return outRev;
    }
};