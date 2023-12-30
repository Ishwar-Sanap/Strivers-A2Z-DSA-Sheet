/*
Input:
N = 5
Arr[] = {3, 5, 0, 0, 4}
Output: 3 5 4 0 0

Explanation: The non-zero elements
preserve their order while the 0
elements are moved to the right.
*/
void pushZerosToEnd(int arr[], int n)
{
    // code here

    int curr = 0, i = 0;

    while (curr < n)
    {
        if (arr[curr] != 0)
        {
            arr[i] = arr[curr];
            i++;
        }

        curr++;
    }

    while (i < n)
    {
        arr[i] = 0;
        i++;
    }
}