#include <bits/stdc++.h>
using namespace std;


/*
Input:
N = 10
Arr[] = {-5, -2, 5, 2, 4, 7, 1, 8, 0, -8}
Output:
5 -5 2 -2 4 -8 7 1 8 0
Explanation : Positive elements : 5,2,4,7,1,8,0
Negative elements : -5,-2,-8

*/
void rearrange(int arr[], int n)
{
    vector<int> temp;

    for (int i = 0; i < n; i++)
        if (arr[i] >= 0)
            temp.push_back(arr[i]);

    int neg = temp.size();

    for (int i = 0; i < n; i++)
        if (arr[i] < 0)
            temp.push_back(arr[i]);

    int p = 0, ne = neg;

    int i = 0;
    while (i < n - 1 && p < neg && ne < n)
    {
        arr[i] = temp[p];
        arr[i + 1] = temp[ne];

        p++;
        ne++;
        i += 2;
    }

    while (p < neg)
    {
        arr[i] = temp[p];
        p++;
        i++;
    }
    while (ne < n)
    {
        arr[i] = temp[ne];
        ne++;
        i++;
    }
}