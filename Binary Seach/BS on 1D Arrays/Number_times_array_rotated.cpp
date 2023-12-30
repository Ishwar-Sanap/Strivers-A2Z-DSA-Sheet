
/*
Given an ascending sorted rotated array Arr of distinct integers of size N. The array is right rotated K times. Find the value of K.

Example 1:

Input:
N = 5
Arr[] = {5, 1, 2, 3, 4}
Output: 1
Explanation: The given array is 5 1 2 3 4.
The original sorted array is 1 2 3 4 5.
We can see that the array was rotated
1 times to the right.
*/

int findKRotation(int arr[], int n)
{
    // code here
    int s = 0, e = n - 1;
    int ans = arr[0];
    int sIndex = 0;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;

        // Identifying the sorted half

        // left half is sorted
        if (arr[s] <= arr[mid])
        {
            if (arr[s] < ans)
            {
                ans = arr[s];
                sIndex = s;
            }
            s = mid + 1;
        }

        // right half is sorted
        else
        {
            if (arr[mid] < ans)
            {
                ans = arr[mid];
                sIndex = mid;
            }
            e = mid - 1;
        }
    }
    return sIndex;
}