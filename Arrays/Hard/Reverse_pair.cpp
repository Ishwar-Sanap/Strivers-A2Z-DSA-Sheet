#include <bits/stdc++.h>
using namespace std;

/*
Given an integer array nums, return the number of reverse pairs in the array.

A reverse pair is a pair (i, j) where:

0 <= i < j < nums.length and
nums[i] > 2 * nums[j].

Input: nums = [1,3,2,3,1]
Output: 2
Explanation: The reverse pairs are:
(1, 4) --> nums[1] = 3, nums[4] = 1, 3 > 2 * 1
(3, 4) --> nums[3] = 3, nums[4] = 1, 3 > 2 * 1
*/


int res = 0;

/*
For each integer in the first part, count the number of integers that satisfy the condition (nums[i] > 2 * nums[j].) 
from the second part. Use the pointer to help you in the counting process.
*/
int getReversePair(vector<int> &arr, int s, int mid, int e)
{
    int idx1 = s, idx2 = mid + 1;
    int j = mid + 1;
    int cnt = 0;
    for (int i = s; i <= mid; i++)
    {
        while (j <= e && arr[i] > (long long)2 * arr[j])
            j++;

        cnt += (j - idx2);
    }
    return cnt;
}
void mergeTwoSortedArray(vector<int> &arr, int s, int mid, int e)
{
    int idx1 = s;       // pointing two 1st array
    int idx2 = mid + 1; // pointing two 2nd array

    vector<int> temp;

    res += getReversePair(arr, s, mid, e);

    while (idx1 <= mid && idx2 <= e)
    {
        if (arr[idx1] > arr[idx2])
        {
            temp.push_back(arr[idx2]);
            idx2++;
        }
        else
        {
            temp.push_back(arr[idx1]);
            idx1++;
        }
    }

    while (idx1 <= mid)
    {
        temp.push_back(arr[idx1]);
        idx1++;
    }

    while (idx2 <= e)
    {
        temp.push_back(arr[idx2]);
        idx2++;
    }

    int i = s;
    for (int ele : temp)
    {
        arr[i] = ele;
        i++;
    }
}
void mergeSort(vector<int> &arr, int s, int e)
{
    if (s >= e)
        return;

    int mid = s + (e - s) / 2;

    mergeSort(arr, s, mid);
    mergeSort(arr, mid + 1, e);

    mergeTwoSortedArray(arr, s, mid, e);
}
int main()
{
    vector<int> arr = {2, 3, 6, 4, 3, 7};

    mergeSort(arr, 0, 4);
    cout << res << endl;

    return 0;
}