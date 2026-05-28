#include <bits/stdc++.h>
using namespace std;

//* brute force - TLE
//  class Solution {
//  public:
//      int suffix(string query,string container){
//          int i = query.size()-1;
//          int j = container.size()-1;
//          int len = 0;
//          for(;i>=0 && j>=0;i--,j--){
//              if(query[i]==container[j])len++;
//              else break;
//          }
//          return len;
//      }
//      vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
//          int n = wordsQuery.size();
//          int m = wordsContainer.size();
//          vector<int>ans;
//          for(int i=0;i<n;i++){
//              int maxi_suffix = -1;
//              int len_container = INT_MAX;
//              int index = 0;
//              for(int j=0;j<m;j++){
//                  int curr_suffix = suffix(wordsQuery[i],wordsContainer[j]);
//                  if(curr_suffix > maxi_suffix){
//                          maxi_suffix = curr_suffix;
//                          len_container = wordsContainer[j].length();
//                          index = j;
//                  }
//                  else if(curr_suffix == maxi_suffix){
//                      if(len_container>wordsContainer[j].length()){
//                          len_container = wordsContainer[j].length();
//                          index = j;
//                      }
//                  }
//              }
//              ans.push_back(index);
//          }
//          return ans;
//      }
//  };

//* optimized by trie structure
class Solution
{
public:
    class TrieNode
    {
    public:
        int child[26];
        int len, idx;
        TrieNode()
        {
            memset(child, -1, sizeof(child));
            len = 1e9;
            idx = -1;
        }
    };
    vector<int> stringIndices(vector<string> &wordsContainer, vector<string> &wordsQuery)
    {
        vector<TrieNode> trie(1);
        for (int i = 0; i < wordsContainer.size(); i++)
        {
            string &s = wordsContainer[i];
            int n = s.size();
            int node = 0;

            if (n < trie[node].len)
            {
                trie[node].len = n;
                trie[node].idx = i;
            }
            for (int j = n - 1; j >= 0; j--)
            {
                int c = s[j] - 'a';
                if (trie[node].child[c] == -1)
                {
                    trie[node].child[c] = trie.size();
                    trie.emplace_back();
                }
                node = trie[node].child[c];
                if (n < trie[node].len)
                {
                    trie[node].len = n;
                    trie[node].idx = i;
                }
            }
        }
        vector<int> ans;
        for (string &w : wordsQuery)
        {
            int node = 0;
            for (int j = w.size() - 1; j >= 0; j--)
            {
                int c = w[j] - 'a';
                if (trie[node].child[c] == -1)
                {
                    break;
                }
                node = trie[node].child[c];
            }
            ans.push_back(trie[node].idx);
        }
        return ans;
    }
};
