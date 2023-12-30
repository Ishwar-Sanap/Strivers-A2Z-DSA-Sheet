#include<bits/stdc++.h>
using namespace std;
/*
Input: 
n = 4, arr1[] = [1 3 5 7] 
m = 5, arr2[] = [0 2 6 8 9]
Output: 
arr1[] = [0 1 2 3]
arr2[] = [5 6 7 8 9]
*/
void merge(long long arr1[], long long arr2[], int n, int m)
{
    // code here
    int i = n - 1;
    int j = 0;

    while (i >= 0 && j < m)
    {
        if (arr1[i] > arr2[j])
            swap(arr1[i--], arr2[j++]);

        else
            j++;
        
    }

    sort(arr1, arr1 + n);
    sort(arr2, arr2 + m);
}