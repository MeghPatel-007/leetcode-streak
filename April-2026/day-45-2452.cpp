#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> result;

        for (string &q : queries) {
            for (string &d : dictionary) {
                int diff = 0;

                for (int i = 0; i < q.size(); i++) {
                    if (q[i] != d[i]) diff++;
                    if (diff > 2) break; // early exit
                }

                if (diff <= 2) {
                    result.push_back(q);
                    break; // no need to check more dictionary words
                }
            }
        }

        return result;
    }
};
