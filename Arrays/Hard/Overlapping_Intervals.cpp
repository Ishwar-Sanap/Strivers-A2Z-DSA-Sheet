#include <bits/stdc++.h>
using namespace std;

/*
Intervals = {{1,3},{2,4},{6,8},{9,10}}
Output: {{1, 4}, {6, 8}, {9, 10}}
*/
vector<vector<int>> overlappedInterval(vector<vector<int>> &intervals)
{
    // Code here
    vector<vector<int>> res;
    sort(intervals.begin(), intervals.end());

    int n = intervals.size();

    int s = 0, e = 0;
    int i = 0;
    while (i < n)
    {
        s = intervals[i][0];
        e = intervals[i][1];

        while (i < n - 1 && intervals[i + 1][0] <= e)
        {
            e = max(e, intervals[i + 1][1]);
            i++;
        }

        res.push_back({s, e});

        i++;
    }
    return res;
}