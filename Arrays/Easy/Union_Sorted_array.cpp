
#include <bits/stdc++.h>
using namespace std;

/*
n = 5, arr1[] = {1, 2, 3, 4, 5}
m = 3, arr2 [] = {1, 2, 3}
Output: 1 2 3 4 5
Explanation: Distinct elements including
both the arrays are: 1 2 3 4 5.
*/

// TC O(N+M) SC O(1)
vector<int> findUnion(int arr1[], int arr2[], int n, int m)
{
    // Your code here
    // return vector with correct order of elements

    vector<int> res;
    int i = 0, j = 0;

    while (i < n && j < m)
    {
        if (arr1[i] == arr2[j])
        {
            // as we inserting in ascending order we check previously inseted element is same as current element
            if (res.size() == 0)
                res.push_back(arr1[i]);
            else if (res[res.size() - 1] != arr1[i])
            {
                res.push_back(arr1[i]);
            }

            i++;
            j++;
        }
        else if (arr1[i] < arr2[j])
        {
            if (res.size() == 0)
                res.push_back(arr1[i]);
            else if (res[res.size() - 1] != arr1[i])
            {
                res.push_back(arr1[i]);
            }

            i++;
        }
        else if (arr2[j] < arr1[i])
        {
            if (res.size() == 0)
                res.push_back(arr2[j]);
            else if (res[res.size() - 1] != arr2[j])
            {
                res.push_back(arr2[j]);
            }

            j++;
        }
    }

    while (i < n)
    {
        if (res.size() == 0)
            res.push_back(arr1[i]);
        else if (res[res.size() - 1] != arr1[i])
        {
            res.push_back(arr1[i]);
        }
        i++;
    }
    while (j < m)
    {
        if (res.size() == 0)
            res.push_back(arr2[j]);
        else if (res[res.size() - 1] != arr2[j])
        {
            res.push_back(arr2[j]);
        }
        j++;
    }

    return res;
}