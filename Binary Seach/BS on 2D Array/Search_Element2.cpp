
#include <bits/stdc++.h>
using namespace std;
/*
Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:

1)Integers in each row are sorted in ascending from left to right.
2)Integers in each column are sorted in ascending from top to bottom.

ex :
 1 4  5  6
 2 3  7  8
 9 10 11 12

 Above matrix is sorted in both row and column wise
 but we can't apply binary seach like previous question because starting element of row is may or may not greter than previous row last element

 We are seeing that we can traverse from 4 corners

 TOP Left (All the elements left to right and top to bottom are incresing ) so we cannot start traversal

 Top Right (All the elements right to left Decresing and top to bottom are Incresing ) so we can start traversal

 Bottom Left (All the elements right to left Incresing and bottom to Top are Decresing ) so we can start traversal

 Bottom Right  (All the elements right to left and bottom to top are decresing ) so we cannot start traversal

*/

// TC O(n+m)
bool searchMatrix(vector<vector<int>> &arr, int target)
{
    int n = arr.size(), m = arr[0].size();

    int r = 0, c = m - 1; // start from Top Right

    while (r < n && c >= 0)
    {
        if (arr[r][c] == target)
            return 1;

        else if (arr[r][c] < target)
            r++;
        else
            c--;
    }
    return 0;
}



bool binarySearch(vector<int> &row, int target)
{
    int s = 0, e = row.size() - 1;

    while (s <= e)
    {
        int mid = (s + e) / 2;

        if (row[mid] == target)
            return true;

        if (row[mid] > target)
            e = mid - 1;
        else
            s = mid + 1;
    }
    return false;
}

//TC O(n * log(m))
bool searchMatrix2(vector<vector<int>> &arr, int target)
{
    int n = arr.size(), m = arr[0].size();

    for (int i = 0; i < n; i++) // Traverse every row
    {
        if (target >= arr[i][0] && target <= arr[i][m - 1]) // cheking if row containing answer
        {
            bool ret = binarySearch(arr[i], target); 

            if (ret)
                return true;
        }
    }
    return false;
}
int main()
{
    vector<vector<int>> arr = {{1, 4, 5, 6}, {2, 3, 7, 8}, {9, 10, 11, 12}};

    cout << searchMatrix(arr, 9) << endl;

    return 0;
}