
int missingNumber(int arr[], int N)
{
    // Your code goes here

    /*
    Assume the given array is: {1, 2, 4, 5} and N = 5.

    XOR of (1 to 5) i.e. xor1 = (1^2^3^4^5)
    XOR of array elements i.e. xor2 = (1^2^4^5)

    XOR of xor1 and xor2 = (1^2^3^4^5) ^ (1^2^4^5)
                = (1^1)^(2^2)^(3)^(4^4)^(5^5)
                = 0^0^3^0^0 = 0^3 = 3.

    The missing number is 3.
        */

    int OneToNXor = 0;
    for (int i = 1; i <= N; i++)
        OneToNXor ^= i;

    for (int i = 0; i < N - 1; i++)
        OneToNXor ^= arr[i];

    return OneToNXor;



    /// Alternative solution;

    // int sum = (n * (n+1))/2;

    // for(int ele : arr)sum -= ele;
    // return sum;

}