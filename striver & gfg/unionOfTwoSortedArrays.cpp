#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> &arr1, vector<int> &arr2)
{
    //* maps
    // map<int,int>m;
    // vector<int>ans;
    // for(int& a:arr1){
    //     m[a]++;
    // }
    // for(int& a:arr2){
    //     m[a]++;
    // }
    // for(auto& [k,v]:m){
    //     ans.push_back(k);
    // }
    // return ans;
    //* set
    // set<int> s;
    // for (int &a : arr1)
    // {
    //     s.insert(a);
    // }
    // for (int &a : arr2)
    // {
    //     s.insert(a);
    // }
    // vector<int> ans(s.begin(), s.end());
    // return ans;
    //* 2 pointer
    vector<int> ans;
    int i,j = 0;
    while(i < arr1.size() && j < arr2.size()){
        if(arr1[i] < arr2[j]){
            ans.push_back(arr1[i++]);
        }else if(arr1[i]==arr2[j]){
            ans.push_back(arr1[i++]);
            j++;
        }else{
            ans.push_back(arr1[j++]);
        }
    }
    return ans;
}

int main()
{
    // testcase-1
    vector<int> arr1 = {1, 2, 3, 4, 5};
    vector<int> arr2 = {2, 3, 4, 4, 5};
    vector<int> ans = solution(arr1, arr2);
    for (int a : ans)
    {
        cout << a << " ";
    }
    return 0;
}
