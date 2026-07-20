#include<bits/stdc++.h>
using namespace std;

int solution(vector<int>& arr,int k) {
    int sum = arr[0];
    int x = 0,y = 0;
    int len = 0;
    while(y < arr.size()){
        while(x <= y && sum > k){
            sum -= arr[x];
            x++;
        }
        if(sum == k)len = max(len,y-x+1);
        y++;
        if(y < arr.size())sum += arr[y];
    }
    return len;
}

int main() {
    // testcase-1
    vector<int> arr = {10, 5, 2, 7, 1, 9};
    int k = 15;
    cout << solution(arr,k);
    return 0;
}

