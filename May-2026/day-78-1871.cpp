#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // mine
    //  bool solve(string &s,int minJmp,int maxJmp,int &minJump,int &maxJump){
    //      for(int j=minJmp;j<=maxJmp;j++){
    //          if(s[j]=='0'){
    //              if(j==s.length()-1)return true;
    //               if(solve(s,j+minJump,min(j+maxJump,int(s.length())-1),minJump,maxJump))return true;
    //          }
    //      }
    //      return false;
    //  }
    //  bool canReach(string s, int minJump, int maxJump) {
    //      return  solve(s,0+minJump,min(0+maxJump,int(s.length())-1),minJump,maxJump);
    //  }

    // optimzed
    //  vector<int>t;
    //  bool solve(string &s,int i,int& minJump,int& maxJump){
    //      if(t[i]!=-1)return t[i];
    //      for(int next=i+minJump;next<=min(i+maxJump,int(s.length())-1);next++){
    //          if(s[next]=='0'){
    //              if(next==s.length()-1)return t[i] = 1;
    //              if(solve(s,next,minJump,maxJump))return t[i] = 1;
    //          }
    //      }
    //      return t[i] = 0;
    //  }
    //  bool canReach(string s, int minJump, int maxJump) {
    //      t.resize(s.length(),-1);
    //      return solve(s,0,minJump,maxJump);
    //  }

    bool canReach(string s, int minJump, int maxJump)
    {

        int n = s.length();

        vector<bool> reachable(n, false);
        reachable[0] = true;

        int farthest = 0;

        for (int i = 0; i < n; i++)
        {

            if (!reachable[i])
                continue;

            int start = max(i + minJump, farthest + 1);
            int end = min(i + maxJump, n - 1);

            for (int j = start; j <= end; j++)
            {

                if (s[j] == '0')
                {
                    reachable[j] = true;

                    if (j == n - 1)
                        return true;
                }
            }

            farthest = max(farthest, end);
        }

        return reachable[n - 1];
    }
};
