#include<bits/stdc++.h>
using namespace std;

/*
    Kadanes Algorithms 

    when the sum of array element becomes negative then there is no sense of adding furter elements in it
    so we calculate the answere at that point and making sum == 0
*/

long long maxSubarraySum(int arr[], int n)
{

    // Your code here

    long long res = LONG_LONG_MIN;
    long long sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        res = max(res, sum);

        if (sum < 0)
            sum = 0;
    }

    return res;
}

int main()
{
    int arr[] = {1,2,3,-2,5};
    cout<< maxSubarraySum(arr ,5 )<<endl;

    return 0;
}