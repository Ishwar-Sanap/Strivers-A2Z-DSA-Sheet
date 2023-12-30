/*Given an array arr[] of size N and an integer K, the task is to left rotate the array K indexes
Input: N = 7, K = 2
arr[] = {1, 2, 3, 4, 5, 6, 7}
Output: 3 4 5 6 7 1 2
Explanation: Rotation of the above
array by 2 will make the output array .
*/


/*
    TC O(N)
    SC O(K)
*/

#include<bits/stdc++.h>
using namespace std;
void leftRotate(int arr[], int k, int n)
{
    // Your code goes here

    k = k % n;
    if (k == 0)
        return;

    int temp[k] = {0};

    for (int i = 0; i < k; i++)
        temp[i] = arr[i];

    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (i < n - k)
            arr[i] = arr[i + k];

        else
        {
            arr[i] = temp[j];
            j++;
        }
    }
}

/*
 1 2 3 4 5 6   k = 2

 step1 : 2 1 3 4 5 6
 step2 : 2 1 6 5 4 3
 step3 : 3 4 5 6 1 2

*/

void reverse(int s , int e, int arr[])
{
    while(s < e)
    swap(arr[s++],arr[e--]);
}
void leftRotate(int arr[] , int k , int n)
{
    k = k %n;
    if(k == 0) return;


    reverse(0 , k-1, arr);
    reverse(k , n-1 , arr);
    reverse(0 , n-1, arr);

}