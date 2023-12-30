#include <bits/stdc++.h>
using namespace std;

/*
    Input:
N = 3, M = 3, K = 4
A[] = {{1, 2, 3},
       {4, 5, 6},
       {7, 8, 9}}
Output:
6
Explanation: Spiral traversal of matrix:
{1, 2, 3, 6, 9, 8, 7, 4, 5}. Fourth element
is 6.

*/
int findK(vector<vector<int>> &a, int n, int m, int k)
{
    int sr = 0, sc = 0, er = n - 1, ec = m - 1;

    while (k > 0)
    {
        for (int i = sr; i <= ec && k > 0; i++)
        {
            k--;
            if (k == 0)
                return a[sr][i];
        }
        sr++;

        for (int i = sr; i <= er && k > 0; i++)
        {
            k--;
            if (k == 0)
                return a[i][ec];
        }
        ec--;

        for (int i = ec; i >= sc && k > 0; i--)
        {
            k--;
            if (k == 0)
                return a[er][i];
        }
        er--;

        for (int i = er; i >= sr && k > 0; i--)
        {
            k--;
            if (k == 0)
                return a[i][sc];
        }
        sc++;
    }
    return -1;
}