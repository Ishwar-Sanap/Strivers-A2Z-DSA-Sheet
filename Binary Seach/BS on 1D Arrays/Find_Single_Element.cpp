#include <bits/stdc++.h>
using namespace std;

/*
Input: nums = [1,2,2,3,3,4,4,8,8]
Output: 1

Input: nums = [2,2,3,3,4,4,8]
Output: 8
*/
int singleNonDuplicate(vector<int> &arr)
{
    int s = 0, e = arr.size() - 1;
    int n = arr.size();

    // Handle the edge cases properly for mid == 0 and mid == n
    while (s <= e)
    {
        int mid = s + (e - s) / 2;

        if (mid > 0 && arr[mid] == arr[mid - 1])
        {
            if ((mid - 1) % 2 == 0) // element are same of even and odd indexs
                s = mid + 1;
            else
                e = mid - 1;
        }

        else if (mid + 1 < n && arr[mid] == arr[mid + 1])
        {
            if ((mid + 1) % 2 == 0) // odd and even idexes are same element
                e = mid - 1;

            else
                s = mid + 1;
        }

        else // In this case mid mid and mid+1 or mid and mid-1 are different
            return arr[mid];
    }
    return -1;
}

int singleNonDuplicate2(vector<int>& arr) {
        
        int s = 1 , e = arr.size()-2; // Note as we start from 1 and n-2 then we never go out of bound
        int n= arr.size();

        
    // Handle the edge cases properly for mid == 0 and mid == n
        if(n == 1) return arr[0];
        if(arr[0] != arr[1]) return arr[0];
        if(arr[n-1] != arr[n-2]) return arr[n-1];

        while( s <= e)
        {
            int mid = s+ (e-s)/2;

            if(arr[mid] != arr[mid-1] && arr[mid] != arr[mid+1])
                return arr[mid];


            if(arr[mid] == arr[mid-1])
            {
                if((mid-1) % 2 == 0) //element are same of even and odd indexs
                    s = mid+1;
                else
                    e = mid-1;
            }

            else if( arr[mid] == arr[mid+1])
            {
                if((mid+1) % 2 == 0) // odd and even idexes are same element
                e = mid-1;

                else
                s = mid+1;
            }


        }
        return -1;
    }