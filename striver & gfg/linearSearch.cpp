#include<bits/stdc++.h>
using namespace std;

int solution(vector<int>& arr,int num) {
    int n = arr.size();
    for(int i=0;i<n;i++){
        if(num == arr[i])return i;
    }
    return 0;
}

int main() {
    // testcase-1
    vector<int> arr = {1,12,43,223};
    int num = 12;
    cout << solution(arr,num);
    return 0;
}
