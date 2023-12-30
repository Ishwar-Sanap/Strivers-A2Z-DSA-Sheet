#include<bits/stdc++.h>
using namespace std;

/*
Input:
N = 5
A = {1, 1, 2, 5, 5}
Output: 2
*/

// TC O(Log(N))  SC O(1) 
int search(int arr[], int N)
{
    // code

    int s = 0, e = N - 1;

    while (s <= e)
    {
        int mid = s + (e - s) / 2;

        if (mid+1 <N && arr[mid] == arr[mid + 1])
        {
            // even odd index having same number
            if (mid % 2 == 0)
                s = mid + 1;
            else
                e = mid - 1; // odd even pair having same number
        }
        else if (mid > 0 && arr[mid] == arr[mid - 1])
        {
            if ((mid - 1) % 2 == 0)
                s = mid + 1; // even odd index having same number
            else
                e = mid - 1; // odd even pair having same number
        }
        else
            return arr[mid];
    }
    return -1;
}

// Another approach
// By taking or of all elements of the array we can get the element that appears only once
// TC O(N)  , SC(1) 
int main()
{
    int arr[] ={ 1,2,2};

    cout<<search(arr,3);

    return 0;
}