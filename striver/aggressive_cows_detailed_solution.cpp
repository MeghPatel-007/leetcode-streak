#include<bits/stdc++.h>
using namespace std;

bool minDistCows(vector<int>&arr,int dist,int& expCows,int& n){
    int cows = 1;
    int j=0;
    for(int i=1;i<n;i++){
        if(arr[i]-arr[j] >= dist){
            cows++;
            j=i;
        }
    }
    return cows >= expCows;
}
int solution(vector<int>& arr,int n,int k) {
    sort(begin(arr),end(arr));
    int l = 1;
    int r = arr[n-1]-arr[0];
    while(l<=r){
        int mid = l + (r-l)/2;
        if(minDistCows(arr,mid,k,n)){
            l = mid + 1;
        }else{
            r = mid - 1;
        }
    }
    return r;
}

int main() {
    // testcase-1
    // vector<int> arr = {0,3,4,7,10,9};
    vector<int> arr = {4,2,1,3,6};
    int agCows = 2;
    cout << solution(arr,arr.size(),agCows);
    return 0;
}
