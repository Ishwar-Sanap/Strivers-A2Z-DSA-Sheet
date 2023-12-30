/*
You are given an m x n integer matrix matrix with the following two properties:

1) Each row is sorted in non-decreasing order.
2) The first integer of each row is greater than the last integer of the previous row.

Given an integer target, return true if target is in matrix or false otherwise.

You must write a solution in O(log(m * n)) time complexity
*/

#include <bits/stdc++.h>
using namespace std;

// If we flatten the given 2D matrix to a 1D array, the 1D array will also be sorted.
// By utilizing binary search on this sorted 1D array to locate the
//  ‘target’ element, we can further decrease the time complexity.
int matSearch(vector<vector<int>> &arr,int X)
{
    int n = arr.size(), m = arr[0].size();

    int s = 0, e = n * m - 1;
    while (s <= e)
    {
        int mid = (s + e) / 2;

        // For getting row we use mid / col
        // every row starting element index is multiple of col so by using mid % col we get col index

        int val = arr[mid / m][mid % m];

        if (val == X)
            return 1;

        else if (val > X)
            e = mid - 1;
        else
            s = mid + 1;
    }
    return 0;
}

int main()
{
    vector<vector<int>> arr = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};

    cout<<matSearch(arr,34)<<endl;

    return 0;
}