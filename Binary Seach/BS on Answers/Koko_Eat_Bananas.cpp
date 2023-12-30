/*
Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. 
The guards have gone and will come back in h hours.
Koko can decide her bananas-per-hour eating speed of k. 
Each hour, she chooses some pile of bananas and eats k bananas from that pile. 
If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.

Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.
Return the minimum integer k such that she can eat all the bananas within h hours.

Example 1:

Input: piles = [3,6,7,11], h = 8
Output: 4
Example 2:

Input: piles = [30,11,23,4,20], h = 5
Output: 30
*/

#include<bits/stdc++.h>
using namespace std;

bool canEatAllBananas(int speed, vector<int> &piles, int h)
{
    int cnthr = 0;

    int n = piles.size();

    for (int i = 0; i < n; i++)
    {
        if (piles[i] % speed == 0)
            cnthr += piles[i] / speed;

        else
            cnthr += (piles[i] / speed) + 1;

        if (cnthr > h)
            return false;
    }

    return true;
}
int minEatingSpeed(vector<int> &piles, int h)
{

    int maxSpeed = piles[0];
    for (int ele : piles)
        maxSpeed = max(maxSpeed, ele);

    int s = 1, e = maxSpeed;

    int ans = -1;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;

        if (canEatAllBananas(mid, piles, h))
        {
            ans = mid;
            e = mid - 1;
        }

        else
            s = mid + 1;
    }
    return ans;

}