using namespace std;
#include<bits/stdc++.h>
/*
Input : [-2,0,0,2,2] 
Output : [[-2,0,2]]


TC = O(N2)
Sc = O(1)
*/

vector<vector<int>> triplet(vector<int> &nums)
{
    vector<vector<int>> res;
    int n = nums.size();
    sort(nums.begin(), nums.end());

    for (int i = 0; i < n - 2; i++)
    {
        // skippping duplicates
        if (i > 0 && nums[i] == nums[i - 1])
            continue;

        int s = i + 1, e = n - 1;

        while (s < e)
        {
            int sum = nums[i] + nums[s] + nums[e];

            if (sum == 0)
            {
                // skippping duplicates
                if ((nums[s] == nums[s - 1]) && (e < n - 1 && nums[e] == nums[e + 1]))
                {
                    s++;
                    e--;
                }
                else
                {
                    res.push_back({nums[i], nums[s], nums[e]});
                    s++;
                    e--;
                }
            }
            else if (sum < 0)
                s++;
            else if (sum > 0)
                e--;
        }
    }
    return res;
}

int main()
{
    // vector<int> arr = { -1, 0, 1, 2, -1, -4};
    // int n = arr.size();
    // vector<vector<int>> ans = triplet(arr);
    // for (auto it : ans) 
    // {
    //     cout << "[";
    //     for (auto i : it) {
    //         cout << i << " ";
    //     }
    //     cout << "] ";
    // }
    // cout << "\n";

   long long   a;
    cout<<sizeof(a);

    return 0;
}