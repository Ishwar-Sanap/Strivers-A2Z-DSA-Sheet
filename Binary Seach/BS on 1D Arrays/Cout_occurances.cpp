	int getFirstOccurance(int arr[],int n, int k)
{
    int s = 0, e = n - 1;

    int ans = -1;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;

        // It might be answer
        if (arr[mid] == k)
        {
            ans = mid;
            e = mid - 1; // for finding to first occurance go to back
        }

        else if (arr[mid] < k)
            s = mid + 1;

        else if (arr[mid] > k)
            e = mid - 1;
    }
    return ans;
}
 int getLastOccurance(int arr[],int n, int k)
{
    int s = 0, e =n - 1;

    int ans = -1;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;

        // it might be ans
        if (arr[mid] == k)
        {
            ans = mid;
            s = mid + 1; // for getting las occurance go to next
        }

        else if (arr[mid] < k)
            s = mid + 1;

        else if (arr[mid] > k)
            e = mid - 1;
    }
    return ans;
}

    int count(int arr[], int n, int k) {
        // code here
        
        int l =  getLastOccurance(arr,n,k);
        if(l == -1) return 0;
         int f = getFirstOccurance(arr,n,k) ;
        return l - f + 1;
    }