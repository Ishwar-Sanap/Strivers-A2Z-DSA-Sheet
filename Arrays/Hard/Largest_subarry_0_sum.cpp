#include <bits/stdc++.h>
using namespace std;

int maxLen(vector<int> &A, int n)
{
    // Your code here
    unordered_map<int, int> presum;

    int res = 0;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += A[i];

        if (sum == 0)
        {
            res = max(res, i + 1);
        }

        if (presum.find(sum) != presum.end())
        {
            res = max(res, i - presum[sum]);
        }
        else
            presum[sum] = i;
    }
    return res;
}

int main()
{
    vector<int> arr = {1,-1,-1,1};
    cout<<maxLen(arr,4);
}