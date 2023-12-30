#include<bits/stdc++.h>
using namespace std;


// Array May containing duplicates elements

// If array having duplicate their is problem to identifying the sorted half of array

// ex :  3 1 2 3 3 3 3  k = 1

int SerachInRotatedSorted2(vector<int>& arr, int n, int k)
{
     int s = 0, e = arr.size()-1;
  

    while(s <= e)
    {
        int mid = s+ (e-s)/2;

        if(arr[mid] == k) return mid;

        //Edge case
        if(arr[s] == arr[mid] && arr[mid] == arr[e])
        {
            s++;
            e--;
            continue;
        }

        // Identifying the sorted part of the array

        // Left part is sorted
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

        //right part is sorted
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