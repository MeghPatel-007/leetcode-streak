#include <bits/stdc++.h>
using namespace std;

void print(vector<int> arr)
{
    cout << "{ ";
    for (int i = 0; i < (int)arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << "}";
}

bool solve1(int idx, int subseqSum, int &sum, vector<int> subseq, vector<int> &arr)
{
    if (idx >= (int)arr.size())
    {
        if (sum == subseqSum)
        {
            print(subseq);
            return true;
        }
        return false;
    }
    subseq.push_back(arr[idx]);
    subseqSum += arr[idx];
    if (solve1(idx + 1, subseqSum, sum, subseq, arr))
        return true;
    subseq.pop_back();
    subseqSum -= arr[idx];
    if (solve1(idx + 1, subseqSum, sum, subseq, arr))
        return true;
    return false;
}

int solve2(int idx, int subseqSum, int &sum, vector<int> subseq, vector<int> &arr)
{
    if (idx >= (int)arr.size())
    {
        if (sum == subseqSum)
        {
            print(subseq);
            return 1;
        }
        return 0;
    }
    subseq.push_back(arr[idx]);
    subseqSum += arr[idx];
    int l = solve1(idx + 1, subseqSum, sum, subseq, arr);
    subseq.pop_back();
    subseqSum -= arr[idx];
    int r = solve1(idx + 1, subseqSum, sum, subseq, arr);
    return l + r;
}

int main()
{
    int sum = 2;
    vector<int> arr = {1, 2, 1};
    cout << solve1(0, 0, sum, {}, arr) << endl;
    cout << solve2(0, 0, sum, {}, arr) << endl;
}
