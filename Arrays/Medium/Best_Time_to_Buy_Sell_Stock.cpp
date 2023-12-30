#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &arr)
    {
        int n = arr.size();

        int buy = INT_MAX;
        int profit = 0;

        for (int i = 0; i < n; i++)
        {
            if (arr[i] < buy) // buy at lowest price
                buy = arr[i];
            
            else if (arr[i] > buy) // if at any time price is greter than buying price then sell
                profit = max(profit, arr[i] - buy);
        }
        return profit;
    }
};