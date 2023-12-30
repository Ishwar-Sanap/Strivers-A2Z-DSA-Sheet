#include <bits/stdc++.h>
using namespace std;

/*
Given an array of integers nums and an integer threshold, we will choose a positive integer divisor,
 divide all the array by it, and sum the division's result.
 Find the smallest divisor such that the result mentioned above is less than or equal to threshold.

 Input: nums = [1,2,5,9], threshold = 6
Output: 5
*/
int getSum(int divisor, vector<int> &nums, int threshold)
{
    int n = nums.size();
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        // int val = nums[i]/divisor;
        // if(nums[i] % divisor != 0) val++;

        // or
        int val = ((nums[i] - 1) / divisor) + 1;
        sum += val;
    }

    return sum;
}
int smallestDivisor(vector<int> &nums, int threshold)
{

    int maxi = nums[0];
    for (int ele : nums)
        maxi = max(ele, maxi);

    int s = 1, e = maxi;

    int ans = 0;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;

        int sum = getSum(mid, nums, threshold);

        if (sum > threshold) // we need to maximize the divisor so sum will become less
        {
            s = mid + 1;
        }
        else
        {
            ans = mid;
            e = mid - 1;
        }
    }
    return ans;
}