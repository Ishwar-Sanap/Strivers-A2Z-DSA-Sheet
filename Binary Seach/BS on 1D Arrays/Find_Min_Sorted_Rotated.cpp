#include <bits/stdc++.h>
using namespace std;

int findMin(vector<int> &arr)
{
    // Write your code here.

    int s = 0, e = arr.size() - 1;

    int ans = arr[0];

    while (s <= e)
    {
        int mid = s + (e - s) / 2;

        // Identifying the sorted half

        // left half is sorted
        if (arr[s] <= arr[mid])
        {
            ans = min(ans, arr[s]);
            s = mid + 1;
        }

        // right half is sorted
        else
        {
            ans = min(ans, arr[mid]);
            e = mid - 1;
        }
    }
    return ans;
}