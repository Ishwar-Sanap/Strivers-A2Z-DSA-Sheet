#include <bits/stdc++.h>
using namespace std;

/*
    Given an array of integers nums and an integer target, 
    return indices of the two numbers such that they add up to target.

    Input: nums = [2,7,11,15], target = 9
    Output: [0,1]
*/
vector<int> twoSum(vector<int> &nums, int target)
{
    unordered_map<int,int>mp;
    int n = nums.size();
    for(int i = 0;i<n; i++)
    {
        int req = target - nums[i];
        if(mp.count(req))
        {
            return {i , mp[req]};
        }
        mp.insert({nums[i] , i});
    }

    return {};
}
int main()
{   
    vector<int>nums= {2,7,11,15};

    vector<int>ret = twoSum(nums,9);

    cout<<ret[0] << " "<< ret[1]<<endl;

    return 0;
}