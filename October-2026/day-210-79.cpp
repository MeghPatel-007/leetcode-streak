#include <bits/stdc++.h>
using namespace std;

// * backtracking
class Solution
{
public:
    vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    bool find(int idx, int i, int j, vector<vector<char>> &board, string word)
    {
        int n = board.size();
        int m = board[0].size();
        if (idx == word.length())
            return true;
        if (i < 0 || j < 0 || i >= n || j >= m || board[i][j] == '$' || word[idx] != board[i][j])
            return false;
        int temp = board[i][j];
        board[i][j] = '$';
        for (auto &dir : directions)
        {
            int i_ = dir[0] + i;
            int j_ = dir[1] + j;
            if (find(idx + 1, i_, j_, board, word))
                return true;
        }
        board[i][j] = temp;
        return false;
    }
    bool exist(vector<vector<char>> &board, string word)
    {
        int n = board.size();
        int m = board[0].size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (word[0] == board[i][j] && find(0, i, j, board, word))
                {
                    return true;
                }
            }
        }
        return false;
    }
};
