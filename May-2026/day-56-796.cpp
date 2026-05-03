#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool rotateString(string s, string goal)
    {
        // brute force
        //  for(int i=0;i<s.length();i++){
        //      char first = s[0];
        //      for(int i=0;i<s.length();i++){
        //          s[i]=s[i+1];
        //      }
        //      s[s.length()-1]=first;
        //      if(s==goal)return true;
        //  }
        //  return false;

        // optimal
        //  string new_s = s+s;
        //  int j = 0;
        //  for(int i=0;i<new_s.length();i++){
        //      if(goal[j]==new_s[i]){
        //          j++;
        //      }
        //      if(j==goal.length()-1)return true;
        //  }
        //  return false;

        // optimal
        if (s.length() != goal.length())
            return false;
        return (s + s).find(goal) != string::npos;
    }
};
