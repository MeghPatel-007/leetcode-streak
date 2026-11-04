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
    cout << endl;
}

void solve(int idx, vector<int> subseq, vector<int> &arr)
{
    if (idx >= arr.size())
    {
        print(subseq);
        return;
    }
    subseq.push_back(arr[idx]);
    solve(idx + 1, subseq, arr);
    subseq.pop_back();
    solve(idx + 1, subseq, arr);
}

int main()
{
    vector<int> arr = {3, 1, 2};
    solve(0, {}, arr);
    return 0;
}
