#include <bits/stdc++.h>
using namespace std;

/*
n = 6
A[] = {16,17,4,3,5,2}
Output: 17 5 2
*/
vector<int> leaders(int arr[], int n)
{
    vector<int> res;

    int rightLargeEle = arr[n - 1];
    for (int i = n - 1; i >= 0; i--)
    {
        if (arr[i] >= rightLargeEle)
        {
            res.push_back(arr[i]);
            rightLargeEle = arr[i];
        }
    }

    reverse(res.begin(), res.end());

    return res;
}