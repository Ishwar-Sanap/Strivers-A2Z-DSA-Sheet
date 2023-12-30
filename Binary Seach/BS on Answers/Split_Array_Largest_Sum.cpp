#include <bits/stdc++.h>
using namespace std;

/*
Given an integer array nums and an integer k, split nums into k non-empty subarrays such that the largest sum of any subarray is minimized.

Return the minimized largest sum of the split.

A subarray is a contiguous part of the array.

 

Example 1:

Input: nums = [7,2,5,10,8], k = 2
Output: 18
Explanation: There are four ways to split nums into two subarrays.
The best way is to split it into [7,2,5] and [10,8], where the largest sum among the two subarrays is only 18.
*/

/*/////////////////////*******************************************///////////////////////////////////////
/* Painters problems is also same as above question

Given an array/list of length ‘n’, where the array/list represents the boards and each element of the given array/list 
represents the length of each board. Some ‘k’ numbers of painters are available to paint these boards. 
Consider that each unit of a board takes 1 unit of time to paint.

You are supposed to return the area of the minimum time to get this job done of 
painting all the ‘n’ boards under a constraint that any painter will only paint
 the continuous sections of boards.

Example :
Input: arr = [2, 1, 5, 6, 2, 3], k = 2

Output: 11

Explanation:
First painter can paint boards 1 to 3 in 8 units of time and the second painter can paint boards 4-6 in 11 units of time. Thus both painters will paint all the boards in max(8,11) = 11 units of time. It can be shown that all the boards can't be painted in less than 11 units of time.

//////////////////////*******************************************////////////////////////////////////// */




int getParts(int sum, vector<int> &arr)
{
    int n = arr.size();

    int p = 1;
    int psum = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] + psum > sum)
        {
            p++;
            psum = arr[i];
        }

        else
            psum += arr[i];
    }

    return p; // it will returs no of parts array can we make at give sum
}

// Pattern is finding min ( max  ) largest sum of any subarray is minimized.
 int splitArray(vector<int> &arr, int k)
{

    int maxi = *max_element(arr.begin(), arr.end());
    int TotalSum = accumulate(arr.begin(), arr.end(), 0);

    int s = maxi, e = TotalSum;

    // int ans = -1;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;

        int parts = getParts(mid, arr);

        if (parts > k)
        {
            s = mid + 1; // if we increse then parts becomes less
        }

        else
        {
            // ans = mid;
            e = mid - 1;
        }
    }

    // return ans;
    return s; // by using polarity concept we can say initally s has not ans and e as ans when loop brek s contins our desire output
}