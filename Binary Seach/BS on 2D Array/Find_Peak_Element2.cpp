#include <bits/stdc++.h>
using namespace std;

/*
A peak element in a 2D grid is an element that is strictly greater than all of its adjacent neighbors to the left, right, top, and bottom.

Given a 0-indexed m x n matrix mat where no two adjacent cells are equal, find any peak element mat[i][j] and return the length 2 array [i,j].

You may assume that the entire matrix is surrounded by an outer perimeter with the value -1 in each cell.

You must write an algorithm that runs in O(m log(n)) or O(n log(m)) time.
*/

int getMaxi(int col, vector<vector<int>> &mat)
{
    int n = mat.size();
    int MaxEleRow = 0;

    for (int i = 0; i < n; i++)
    {
        if (mat[i][col] > mat[MaxEleRow][col])
        {
            MaxEleRow = i;
        }
    }
    return MaxEleRow;
}

// By finding max element from array we can also solve this problem But TC O(N*M) // as we get max element so every elements from it's neighbour are lesser
// Better Approach is O(n log(m))
vector<int> findPeakGrid(vector<vector<int>> &arr)
{

    int n = arr.size(), m = arr[0].size();
    int s = 0, e = m - 1;

    while (s <= e)
    {
        int mid = (s + e) / 2;

        int MaxEleRow = getMaxi(mid, arr);

        int i = MaxEleRow, j = mid;

        // As we pick maxelement from the column so element above and below it are lesser

        if (j + 1 < m && arr[i][j + 1] > arr[i][j])
            s = mid + 1;

        else if (j > 0 && arr[i][j - 1] > arr[i][j])
            e = mid - 1;

        else
            return {i, j};
    }
    return {-1, -1};
}