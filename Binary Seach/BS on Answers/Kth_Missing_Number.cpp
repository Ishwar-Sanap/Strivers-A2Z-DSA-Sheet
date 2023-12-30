
#include <bits/stdc++.h>
using namespace std;

/*
Given an array arr of positive integers sorted in a strictly increasing order,
 and an integer k.
Return the kth positive integer that is missing from this array.

Example 1:

Input: arr = [2,3,4,7,11], k = 5
Output: 9
Explanation: The missing positive integers are [1,5,6,8,9,10,12,13,...]. The 5th missing positive integer is 9.
*/

int findKthPositive(vector<int> &arr, int k)
{
    int n = arr.size();
    int s = 0, e = n - 1;

    while (s <= e)
    {
        int mid = s + (e - s) / 2;

        // as array is sorted we can find till that point how many elements are missings
        int missings = arr[mid] - mid - 1; 
        
        if (k > missings)
            s = mid + 1;

        else
        {
            e = mid - 1;
        }
    }
    return s + k; // start (s) is pointing to index from where k elements are missings
}