#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool checkStrings(string s1, string s2) {
        //mine
        // map<char,int>map_s1;
        // map<char,int>map_s2;
        // for(int i=0;i<s1.length();i++){
        //     map_s1[s1[i]] += i;
        // }
        // for(int i=0;i<s2.length();i++){
        //     map_s2[s2[i]] += i;
        // }
        // for(auto it:map_s2){
        //     char ch = it.first;
        //     if(map_s1.find(ch)==map_s1.end())return false;
        // }
        // for(auto it:map_s1){
        //     char ch = it.first;
        //     if(map_s2.find(ch)==map_s2.end())return false;
        //     if((map_s1[ch]-map_s2[ch])%2!=0)return false;
        // }
        // return true;
         vector<int> even1(26,0), odd1(26,0);
        vector<int> even2(26,0), odd2(26,0);

        for(int i = 0; i < s1.length(); i++) {
            if(i % 2 == 0) {
                even1[s1[i]-'a']++;
                even2[s2[i]-'a']++;
            } else {
                odd1[s1[i]-'a']++;
                odd2[s2[i]-'a']++;
            }
        }

        return even1 == even2 && odd1 == odd2;
    }
};