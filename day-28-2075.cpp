#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string decodeCiphertext(string encodedText, int rows)
    {
        if (rows == 1)
            return encodedText;

        int n = encodedText.size();
        int cols = n / rows;

        vector<vector<char>> matrix(rows, vector<char>(cols));

        // Fill matrix row-wise
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                matrix[i][j] = encodedText[i * cols + j];
            }
        }

        string result = "";

        // Traverse diagonally
        for (int startCol = 0; startCol < cols; startCol++)
        {
            int i = 0, j = startCol;
            while (i < rows && j < cols)
            {
                result += matrix[i][j];
                i++;
                j++;
            }
        }

        // Remove trailing spaces
        while (!result.empty() && result.back() == ' ')
        {
            result.pop_back();
        }

        return result;
    }
};