#include <bits/stdc++.h>
using namespace std;
int getFirstOccurance(vector<int> &arr, int k)
{
    int s = 0, e = arr.size() - 1;

    int ans = -1;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;

        // It might be answer
        if (arr[mid] == k)
        {
            ans = mid;
            e = mid - 1; // for finding to first occurance go to back
        }

        else if (arr[mid] < k)
            s = mid + 1;

        else if (arr[mid] > k)
            e = mid - 1;
    }
    return ans;
}
int getLastOccurance(vector<int> &arr, int k)
{
    int s = 0, e = arr.size() - 1;

    int ans = -1;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;

        // it might be ans
        if (arr[mid] == k)
        {
            ans = mid;
            s = mid + 1; // for getting las occurance go to next
        }

        else if (arr[mid] < k)
            s = mid + 1;

        else if (arr[mid] > k)
            e = mid - 1;
    }
    return ans;
}

pair<int, int> firstAndLastPosition(vector<int> &arr, int n, int k)
{
    // Write your code here

    pair<int, int> res = make_pair(getFirstOccurance(arr, k), getLastOccurance(arr, k));
    return res;
}