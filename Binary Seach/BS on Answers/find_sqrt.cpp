#include <bits/stdc++.h>
using namespace std;

long long int floorSqrt(long long int x)
{
    // Your code goes here
    long long res = 1;

    long long s = 1, e = x / 2;

    while (s <= e)
    {
        long long mid = s + (e - s) / 2;

        if (mid * mid == x)
            return mid;

        else if (mid * mid > x)
            e = mid - 1;
        else
        {
            res = mid; // for non perfect squres mid can be ans
            s = mid + 1;
        }
    }
    return res;
}

int main()
{
    cout << floorSqrt(51) << endl;
    return 0;
}