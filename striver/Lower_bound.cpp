#include<bits/stdc++.h>
using namespace std;

int solution(int n,int x,vector<int>& arr) {
    int l = 0;
    int r = n-1;
    int ans = -1;
    while(l<=r){
        int mid = l + (r-l)/2;
        if(mid > n)break;
        if(arr[mid] >= x){
            ans = mid;
            r = mid-1;
        }
        else l = mid+1;
    }
    return ans;
}

int main() {
    vector<int> arr = {3,5,8,15,19};
    int x = 9;
    int N = 5;
    cout << solution(N,x,arr);
    return 0;
}
