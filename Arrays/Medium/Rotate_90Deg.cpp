#include <bits/stdc++.h>
using namespace std;

/*
    Given a square matrix of size N x N. The task is to rotate it by 90 degrees in anti-clockwise direction without using any extra space.
N = 3
matrix[][] = {{1, 2, 3},
              {4, 5, 6}
              {7, 8, 9}}
Output:
Rotated Matrix:
3 6 9
2 5 8
1 4 7

*/
void rotateby90(vector<vector<int>> &matrix, int n)
{

    // Transpose of matrix converting row into col
    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < n; j++)
        {
            if (j < i)
                swap(matrix[i][j], matrix[j][i]);
        }
    }

    // For anticlock wise roatation reverse each column
    for (int col = 0; col < n; col++)
    {
        int s = 0, e = n - 1;
        while (s < e)
        {
            swap(matrix[s][col], matrix[e][col]);
            s++;
            e--;
        }
    }
}