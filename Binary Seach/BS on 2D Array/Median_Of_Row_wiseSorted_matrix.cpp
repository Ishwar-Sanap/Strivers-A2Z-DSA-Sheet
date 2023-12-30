#include <bits/stdc++.h>
using namespace std;

/*
R = 3, C = 3
M = [[1, 3, 5],
     [2, 6, 9],
     [3, 6, 9]]
Output: 5
Explanation: Sorting matrix elements gives
us {1,2,3,3,5,6,6,9,9}. Hence, 5 is median.

Partionss
            left part 5 ele       right part 4 ele
            (1 2 3 3 5)     ||| (6 6 9 9 )
*/

int getLesserEqual(int ele, vector<vector<int>> &arr)
{
    int cnt = 0;
    int n = arr.size(), m = arr[0].size();

    for (int i = 0; i < n; i++) // Arr is row wise sorted
    {
        int s = 0, e = m - 1;

        // finding no of Lesserelement in  Every row
        while (s <= e)
        {
            int mid = s + (e - s) / 2;

            if (arr[i][mid] > ele)
                e = mid - 1;
            else
                s = mid + 1;
        }
        // s will be poiting to the column where element at that point is greter than ele

        int noOfLesserEle = s;

        cnt += noOfLesserEle;
    }

    return cnt;
}
int getMax(int col, vector<vector<int>> &arr)
{
    int ans = INT_MIN;

    for (int i = 0; i < arr.size(); i++)
        ans = max(ans, arr[i][col]);

    return ans;
}
int getMin(int col, vector<vector<int>> &arr)
{
    int ans = INT_MAX;

    for (int i = 0; i < arr.size(); i++)
        ans = min(ans, arr[i][col]);

    return ans;
}
int median(vector<vector<int>> &arr, int n, int m)
{
    // code here

    // Arr is soreted in row wise

    int s = getMin(0, arr);
    int e = getMax(m - 1, arr);
    // our median of array should be in between s and e

    int partitions = (n * m) / 2;

    while (s <= e)
    {
        int mid = s + (e - s) / 2;

        // Finding how many element are lesser or equal to mid
        int cnt = getLesserEqual(mid, arr);

        if (cnt <= partitions)
            s = mid + 1;

        else
            e = mid - 1;
    }

    return s;
}

int main()
{
    vector<vector<int>> mat = {{1, 4, 5}};

    cout << median(mat, 1, 3) << endl;

    return 0;
}