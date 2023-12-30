// Input: nums = [3,4,5,1,2]
// Output: true
// Explanation: [1,2,3,4,5] is the original sorted array.
// You can rotate the array by x = 3 positions to begin on the the element of value 3: [3,4,5,1,2].

#include<bits/stdc++.h>
using namespace std;

bool check(vector<int>arr)
{
    int n = arr.size();
    int i = 1;

    // move till array is rotated
    while(i < n && arr[i] >= arr[i-1]) i++;

    //checking the reamaining array is sorted and all elements are less than 0th element
    while(i<n)
    {
        if(i < n-1 && arr[i] <= arr[i+1] && arr[i] <= arr[0])i++;
        else if(i == n-1 && arr[i] <= arr[0]);
        else break;
    }

    return (i >= n);
}

// If the array is sorted and rotated then it has only one pick element 
bool check2(vector<int>arr)
{
    int n = arr.size();
    int i = 0;


}