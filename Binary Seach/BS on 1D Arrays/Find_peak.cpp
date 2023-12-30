int peakElement(int arr[], int n)
{
    // Your code here

    int s = 0, e = n - 1;

    while (s < e)
    {
        int mid = s + (e - s) / 2;

        if (mid > 0 && arr[mid - 1] < arr[mid] && arr[mid] > arr[mid + 1])
            return mid;

        if (arr[mid + 1] > arr[mid])
            s = mid + 1;

        else
            e = mid; // As there are duplictes elements present in neighbour  so mid can also be answer
    }
    return s;
}