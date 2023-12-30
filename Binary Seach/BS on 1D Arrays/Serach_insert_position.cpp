#include <bits/stdc++.h>
using namespace std;
/*
Given a sorted array of distinct integers and a target value, return the index if the target is found.
 If not, return the index where it would be if it were inserted in order.

 Input: nums = [1,3,5,6], target = 5
Output: 2
Example 2:

Input: nums = [1,3,5,6], target = 2
Output: 1
*/
int searchInsert(vector<int> &nums, int target)
{

    int s = 0, e = nums.size() - 1;

    int ans = nums.size(); // If inserted element at the last Position
    // If we don’t find any index, we will return n.
    
    while (s <= e)
    {
        int mid = (s + e) / 2;

        if (target == nums[mid])
            return mid;

        if (target > nums[mid])
            s = mid + 1;

        else
        {
            ans = mid;
            e = mid - 1;
        }
    }
    return ans;
}