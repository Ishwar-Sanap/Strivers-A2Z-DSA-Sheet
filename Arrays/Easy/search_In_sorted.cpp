/*
N = 5, K = 6
arr[] = {1,2,3,4,6}
Output: 1
Exlpanation: Since, 6 is present in 
the array at index 4 (0-based indexing),
output is 1.
*/

int searchInSorted(int arr[], int N, int target)
{

    int i = 0 , j = N-1 ;

    while(i <= j)
    {
        int mid = i + (j - i)/2;

        if(arr[mid] == target) return mid;

        if(target > arr[mid]) i = mid+1;
        else j = mid-1;
    }
    return -1;
}