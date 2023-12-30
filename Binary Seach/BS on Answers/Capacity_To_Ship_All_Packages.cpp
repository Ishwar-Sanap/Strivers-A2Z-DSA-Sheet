#include <bits/stdc++.h>
using namespace std;

/*
A conveyor belt has packages that must be shipped from one port to another within days days.

The ith package on the conveyor belt has a weight of weights[i]. Each day, we load the ship with packages on the conveyor belt (in the order given by weights). We may not load more weight than the maximum weight capacity of the ship.

Return the least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within days days.

Input: weights = [1,2,3,4,5,6,7,8,9,10], days = 5
Output: 15
Explanation: A ship capacity of 15 is the minimum to ship all the packages in 5 days
*/

int daysToShippedAllPackages(int capacity, vector<int> &weights, int days)
{
    int n = weights.size();

    int currWeights = 0;
    int cntDays = 0;

    int i = 0;
    while (i < n)
    {
        currWeights += weights[i];
        if (currWeights > capacity)
        {
            cntDays++;
            currWeights = 0;
            continue;
        }
        i++;
    }

    return cntDays + 1;
}
int shipWithinDays(vector<int> &weights, int days)
{

    int sum = 0;
    int maxi = weights[0];

    for (int w : weights)
    {
        sum += w;
        maxi = max(maxi, w);
    }

    // for shipping all packages we need minimum capacity = max weights and maximum capacity = sum of weights
    int s = maxi, e = sum;
    
    int ans = 0;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;

        int daysReq = daysToShippedAllPackages(mid, weights, days);

        if (daysReq > days)
            s = mid + 1; // increse capacity

        else
        {
            ans = mid;
            e = mid - 1;
        }
    }
    return ans;
}