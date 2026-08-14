#include <bits/stdc++.h>
using namespace std;

bool maxPageBooks(vector<int> &arr, int expStu, int pages, int &n)
{
    int pg = 0;
    int stu = 1;
    int i=0;
    while(i<n){
        if(pg + arr[i] > pages){
            pg = 0;
            stu++;
        }
        pg += arr[i];
        i++;
    }
    return stu > expStu;
}

int solution(vector<int> &arr, int n, int stu)
{
    int l = *max_element(begin(arr), end(arr));
    int r = accumulate(begin(arr), end(arr), 0);
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (maxPageBooks(arr, stu, mid, n))
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    return l;
}

int main()
{
    // testcase-1
    vector<int> arr = {12, 34, 67, 90};
    int students = 2;
    cout << solution(arr, arr.size(), students);
    return 0;
}
