using namespace std;
#include <bits/stdc++.h>

/*
Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
*/
vector<vector<int>> fourSum(vector<int> &nums, int target)
{

    int n = nums.size();
    sort(nums.begin(), nums.end());

    vector<vector<int>> res;
    for (int i = 0; i < n - 3; i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
            continue;
            
        for (int j = i + 1; j < n - 2; j++)
        {
            if (j > i + 1 && nums[j] == nums[j - 1])
                continue;

            int s = j + 1, e = n - 1;

            while (s < e)
            {
                long long sum = (long long)nums[i] + (long long)nums[j] + (long long)nums[e] + (long long)nums[s];
                if (sum == target)
                {
                    if (nums[s] == nums[s - 1] && e < n - 1 && nums[e] == nums[e + 1])
                    {
                        s++;
                        e--;
                    }
                    else
                    {
                        res.push_back({nums[i], nums[j], nums[s], nums[e]});
                        s++;
                        e--;
                    }
                }
                else if (sum < target)
                    s++;
                else
                    e--;
            }
        }
    }
    return res;
}