#include <bits/stdc++.h>
using namespace std;

// * hash map,string,sliding window
int solution(string &s, int k)
{ // atmost k
    int count = 0;
    int n = s.length();
    int i = 0;
    int j = 0;
    unordered_map<char, int> freq;
    while (j < n)
    {
        freq[s[j]]++;
        while (k < freq.size())
        {
            freq[s[i]]--;
            if (freq[s[i]] == 0)
                freq.erase(s[i]);
            i++;
        }
        count += j - i + 1;
        j++;
    }
    return count;
}

int main()
{
    // testcase-1
    string s = "pqpqs";
    int k = 2;
    cout << solution(s, k) - solution(s, k - 1);
    return 0;
}
