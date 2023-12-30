// Input:
// N = 4
// Array = {1, 2, 2, 4}
// Output: 1 2 4
// Explation: 
// After removing all duplicates modify array will contains {1, 2, 4} at first 3 positions so you should return 3 after modify the array.


int remove_duplicate(int arr[], int n)
{
    // code here

    int i = 1, j = 1;

    //  j is index that will pointing to the new array which containig the distinct eleemts
    while (i < n)
    {

        if (arr[i] == arr[i - 1])
        {
            i++;
        }
        else
        {
            arr[j] = arr[i];
            j++;
            i++;
        }
    }
    return j;
}