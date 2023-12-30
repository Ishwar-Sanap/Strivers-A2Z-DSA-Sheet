#include<bits/stdc++.h>
using namespace std;

//  m is maximum of number zeroes allowed to flip
// n is size of array
int findZeroes(int arr[], int n, int m)
{
    // code here

    // Question is to find the longested subarray having consequetive one's by  in that subarray m zeros are allowed
    int i = 0, j = 0;

    int zcnt = 0;
    int res = 0;

    // using the concept of variable size sliding window
    while (j < n)
    {
        if (arr[j] == 0)
            zcnt++;

        if (zcnt <= m)
            j++;

        if (zcnt > m) // we are calculating ansers when the count of zero in window is geter than m
        {

            res = max(res, j - i);

            while (i < j && zcnt > m)
            {
                if (arr[i] == 0)
                    zcnt--;

                i++;
            }

            j++;
        }
    }

    // if at the end zcnt not exceeded the m then also calculate the answer
    if (zcnt <= m)
        res = max(res, j - i);

    return res;
}