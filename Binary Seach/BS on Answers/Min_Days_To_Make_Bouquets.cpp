#include <bits/stdc++.h>
using namespace std;

/*
You are given an integer array bloomDay, an integer m and an integer k.
You want to make m bouquets. To make a bouquet, you need to use k adjacent flowers from the garden.
The garden consists of n flowers, the ith flower will bloom in the bloomDay[i] and then can be used in exactly one bouquet.
Return the minimum number of days you need to wait to be able to make m bouquets from the garden. If it is impossible to make m bouquets return -1.

Input: bloomDay = [7,7,7,7,12,7,7], m = 2, k = 3
Output: 12
*/
int MakeBouquets(int day, vector<int> &bloomDay, int m, int k)
{
    int n = bloomDay.size();

    int i = 0, bouques = 0;
    int cnt = 0; // count of number of  consequetive flowers bloom on give day

    while (i < n)
    {
        if (bloomDay[i] <= day)
            cnt++;

        else
            cnt = 0; // flower not bloom on this day

        if (cnt == k)
        {
            bouques++; // we make one bouquekes.
            cnt = 0;
        }

        i++;
    }

    return bouques;
}

int minDays(vector<int> &bloomDay, int m, int k)
{
    int n = bloomDay.size();

    if (((long long)m * k) > n)
        return -1; // if required flowres are more than no of flowers in garden then we can't make bouques

    int maxDay = bloomDay[0];

    for (int day : bloomDay)
        maxDay = max(maxDay, day);

    // Start from day 1 to max Day can we make bouque
    int s = 1, e = maxDay; // range for binary serach

    int ans = -1;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;

        int bouqueMades = MakeBouquets(mid, bloomDay, m, k);

        if (bouqueMades >= m)
        {
            ans = mid;
            e = mid - 1;
        }

        else
            s = mid + 1;
    }
    return ans;
}


//******************************* Another way *******************************//

bool canMakeBouquets(int day, vector<int> &bloomDay, int m, int k)
{
    int n = bloomDay.size();

    int i = 0;

    int cnt = 0; // count of number of  consequetive flowers bloom on give day
    while (i < n)
    {
        if (bloomDay[i] <= day)
            cnt++;

        else
            cnt = 0;

        if (cnt == k)
        {
            m--; // we make one bouquekes.
            cnt = 0;
        }
        if (m == 0)
            return true;

        i++;
    }

    return false;
}

int minDays(vector<int> &bloomDay, int m, int k)
{

    int n = bloomDay.size();

    if (((long long)m * k) > n)
        return -1; // if required flowres are more than no of flowers in garden then we can't make bouques

    int maxDay = bloomDay[0];
    for (int day : bloomDay)
        maxDay = max(maxDay, day);

    // Start from day 1 to max Day can we make bouque
    int s = 1, e = maxDay;

    int ans = -1;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;

        if (canMakeBouquets(mid, bloomDay, m, k))
        {
            ans = mid;
            e = mid - 1;
        }
        else
            s = mid + 1;
    }
    return ans;
}