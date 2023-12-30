#include <bits/stdc++.h>
using namespace std;

vector<int> maximumsumSubarray(vector<int> &arr, int n)
{
    // Write your code here
    int res = INT_MIN;
    int sum = 0;

    int s = 0;

    int ansStart = 0, ansEnd = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];

        if (sum > res)
        {
            ansStart = s;
            ansEnd = i;

            res = sum;
        }

        if (sum < 0)
        {
            s = i + 1;
            sum = 0;
        }
    }

    vector<int> ans(arr.begin() + ansStart, arr.begin() + ansEnd + 1);

    for(int ele : ans) cout<<ele<<" ";

    return ans;
}

int main()
{
    vector<int>arr ={1,-2,3,2,5};
    maximumsumSubarray(arr ,5 );

    return 0;
}