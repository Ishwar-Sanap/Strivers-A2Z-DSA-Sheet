#include <bits/stdc++.h>
using namespace std;
int subarraysWithXorK(vector<int> arr, int k)
{

    /*
        xr == > xor of some elements
        xr = x ^ k;  x is previous element xor
        taking ^ k on both side

        x = xr ^k  ie we need to find x
    */

    unordered_map<int, int> preXor;
    preXor[0] = 1;

    int n = arr.size();

    int currxr = 0, cnt = 0;

    for (int i = 0; i < n; i++)
    {
        currxr ^= arr[i];

        int req = currxr ^ k;

        if (preXor.find(req) != preXor.end())
            cnt += preXor[req];

        preXor[currxr]++;
    }

    return cnt;
}