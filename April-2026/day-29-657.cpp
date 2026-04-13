#include <bits/stdc++.h>
using namespace std;
// class Solution {
// public:
//     bool judgeCircle(string moves) {
//         int x=0,y=0;
//         for(int i=0;i<moves.length();i++){
//             if(moves[i]=='U')x++;
//             if(moves[i]=='D')x--;
//             if(moves[i]=='L')y--;
//             if(moves[i]=='R')y++;
//         }
//         if(x==0&&y==0){
//             return true;
//         }
//         return false;
//     }
// };

class Solution
{
public:
    bool judgeCircle(string moves)
    {
        int x = 0;
        int y = 0;

        for (char move : moves)
        {
            if (move == 'U')
                y++;
            else if (move == 'D')
                y--;
            else if (move == 'L')
                x--;
            else if (move == 'R')
                x++;
        }

        return x == 0 && y == 0;
    }
};