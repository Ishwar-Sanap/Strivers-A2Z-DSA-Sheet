#include <bits/stdc++.h>
using namespace std;

int lenOfLongSubarr(int arr[], int N, int k)
{
    // Complete the function

    unordered_map<int, int> presum; // map containing  sum of elements till that index
    int currsum = 0;
    int res = 0;


    for (int i = 0; i < N; i++)
    {
        currsum += arr[i];

        if (currsum == k)
            res = max(res, i + 1);

        int req = currsum - k;

        if (presum.find(req) != presum.end())
        {
            int idx = presum[req];
            res = max(res, i - idx);
        }

        // If not present in the map then only update currsum till i
        // because we want the maximum answer so
        if (presum.find(currsum) == presum.end())
            presum[currsum] = i;
    }

    return res;
}

int main()
{
    int arr[] = {3, 2, 4 ,-2 ,1 ,0, 3};
    cout<<lenOfLongSubarr(arr , 7 , 4)<<endl;

    return 0;
}