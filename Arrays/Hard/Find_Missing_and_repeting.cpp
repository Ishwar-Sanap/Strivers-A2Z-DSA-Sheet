#include <bits/stdc++.h>
using namespace std;

/*
Input : 1 2 4 4
output {4 , 3} 4 is repeting and 3 is missing
*/

int findFirstSetBit(int n)
{
    int Zbit = 0;
    while (n > 0)
    {
        if (n & 1 == 1)
            break;

        Zbit++;
        n >>= 1;
    }

    return Zbit;
}
bool isSetBit(int n, int Zbit)
{
    int mask = 1;

    mask = mask << Zbit;

    if ((mask & n) == 0)
        return false;

    return true;
}
vector<int> findTwoElementUsingXor(vector<int> arr, int n)
{

    int AllElementsXor = 0; //[ 1^ 2 ^3 ...^ n] ^ [arr[i] ^ arr[i+1] ..... ^ arr[n-1]]
    for (int i = 0; i < n; i++)
    {
        AllElementsXor ^= i + 1;
        AllElementsXor ^= arr[i];
    }

    // x is repeted and y is missing
    /*
       AllElementsXor = x ^ y
    */
    // Finding the first set bit  (z) from AllElementsXor this bits shows that x and y having different bits

    int Zbit = findFirstSetBit(AllElementsXor);

    // Making the 2 groups that z bit on and off for all element 1 to n  and arr[i] to arr[n-1]

    int group0 = 0, group1 = 0;

    for (int i = 0; i < n; i++)
    {
        if (isSetBit(arr[i], Zbit))
            group1 = group1 ^ arr[i];
        else
            group0 = group0 ^ arr[i];

        if (isSetBit(i + 1, Zbit))
            group1 = group1 ^ i + 1;
        else
            group0 = group0 ^ i + 1;
    }

    // Now we got 2 numbers in group1 and group0 but don't know wchich one is repeted and whcih in missing

    int x = 0, y = 0;

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == group0)
            cnt++;
        if (cnt > 1)
            break;
    }

    if (cnt == 2)
    {
        x = group0;
        y = group1;
    }
    else
    {
        x = group1;
        y = group0;
    }

    return {x, y};
}
vector<int> findTwoElement(vector<int> arr, int n)
{
    // code here

    long long sn = ((long long)n * (n + 1)) / 2;
    long long sn2 = ((long long)n * (n + 1) * (2 * n + 1)) / 6;

    long long s = 0;
    long long s2 = 0;
    for (int ele : arr)
    {
        s += (long long)ele;
        s2 += (long long)ele * (long long)ele;
    }

    // x is repeted and y is missing
    int x = 0, y = 0;

    long long y_minnus_x = sn - s;
    long long y_plus_x = (sn2 - s2) / y_minnus_x;

    y = (int)(y_minnus_x + y_plus_x) / 2;
    x = (int)(y_plus_x - y);

    return {x, y};
}