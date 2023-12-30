#include<bits/stdc++.h>
using namespace std;

// Array only containing Unique elements

// Let’s consider a sorted array: {1, 2, 3, 4, 5}. 
// If we rotate this array at index 3, it will become: {4, 5, 1, 2, 3}. 
// In essence, we moved the element at the last index to the front, 
// while shifting the remaining elements to the right. We performed this process twice.

// this function returs the peak element from array
int getIndex(vector<int>&arr)
{
    int s = 0, e = arr.size();
    int n = arr.size();

    while(s <= e)
    {
        int mid = s+ (e-s)/2;

        if(mid+1 <n && arr[mid  + 1] < arr[mid]) return mid;

        // line 1
        if(arr[mid] >= arr[0]) s = mid+1;
        //line 2
        else if(arr[mid] < arr[0]) e = mid-1;
    }
    return n-1;  // if array is not rotated
}

int binarysearch(vector<int>&arr, int s , int e, int target) {
    // code here
    while(s <= e)
    {
        int mid = s + (e-s)/2; // To avoid the Integer overflow
        
        if(target == arr[mid]) return mid;
        else if(target > arr[mid]) s = mid+1;
        else e = mid-1;
    }
    return -1;
}

int optimizeSerach(vector<int>& arr, int n, int k)
{
     int s = 0, e = arr.size()-1;
  

    while(s <= e)
    {
        int mid = s+ (e-s)/2;

        if(arr[mid] == k) return mid;

        //  Identifying the sorted half of array

        // Left half is sorted
        if(arr[mid] >= arr[s])
        {
            if( k >= arr[s] && k <= arr[mid]) // In sorted range k is present
            {
                if(arr[mid] > k) e  = mid-1;
                else s = mid+1;
            }

            else
             s = mid +1;
        }

        //right half is sorted
        else
        {
            if(k >= arr[mid] && k <= arr[e]) // In sorted range k is present
            {
                if(arr[mid] > k) e  = mid-1;
                else s = mid+1;
            }
            else
            e = mid-1;
        }
    }   

    return -1;
}

int search(vector<int>& arr, int n, int k)
{
    int idx = getIndex(arr);

    // search in line 1
    int ans = binarysearch(arr,0,idx,k);

    if(ans == -1)
        ans = binarysearch(arr,idx+1,n-1,k);

    return ans;

}
