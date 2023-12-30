#include <bits/stdc++.h>
using namespace std;

/*
Given a matrix of  size n x m. Your task is to make Zeroes, that means in whole matrix when you find a zero,
 convert its upper, lower, left, and right value to zero and make that element the
 sum of the upper, lower, left and right value. Do the following tasks according to the initial matrix.

*/

/*
Input
0  16 0  9  6  18
4  4  7  8  8   0
11 4 17  12 0  18
6 14 12  12 4   3

Output:
20 0 32 0 6 0
0 4 0 8 0 44
11 4 17 0 42 0
6 14 12 12 0 3
*/

bool isSafe(int i, int j, int n, int m)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
        return false;
    return true;
}
void MakeZeros(vector<vector<int>> &matrix)
{
    // Code here
    int n = matrix.size(), m = matrix[0].size();

    vector<vector<int>> EMat(n, vector<int>(m, -1));
    EMat = matrix;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (EMat[i][j] == 0)
            {
                int sum = 0;
                // 4 direction
                if (isSafe(i - 1, j, n, m))
                {
                    sum += EMat[i - 1][j];
                    matrix[i - 1][j] = 0;
                }
                if (isSafe(i + 1, j, n, m))
                {
                    sum += EMat[i + 1][j];
                    matrix[i + 1][j] = 0;
                }
                if (isSafe(i, j - 1, n, m))
                {
                    sum += EMat[i][j - 1];
                    matrix[i][j - 1] = 0;
                }
                if (isSafe(i, j + 1, n, m))
                {
                    sum += EMat[i][j + 1];
                    matrix[i][j + 1] = 0;
                }

                matrix[i][j] = sum;
            }
        }
    }
}