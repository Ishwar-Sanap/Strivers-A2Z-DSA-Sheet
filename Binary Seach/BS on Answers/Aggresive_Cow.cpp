// You are given an array consisting of n integers which denote the position of a stall. 
//You are also given an integer k which denotes the number of aggressive cows.
// You are given the task of assigning stalls to k cows such that the minimum distance between any two of them is the maximum possible.

/*
Input:
n=5
k=3
stalls = [10 1 2 7 5]
Output:
4
Explanation:
The first cow can be placed at stalls[0],
the second cow can be placed at stalls[1] and
the third cow can be placed at stalls[4].
The minimum distance between cows, in this case, is 4,
which also is the largest among all possible ways.
*/

#include <bits/stdc++.h>
using namespace std;

bool canPlaceAllCows(int distance, vector<int> &stalls, int k)
{
    int n = stalls.size();

    // we place first cow at 0th position
    int cowplacedIndex = 0;
    k = k - 1;

    for (int i = 1; i < n; i++)
    {

        if (distance <= (stalls[i] - stalls[cowplacedIndex]))
        {
            k--;
            cowplacedIndex = i;
        }

        if (k == 0)
            return true;
    }

    return false;
}
//pattern is  minimum distance between any two of them is the maximum as possible. max(min)
int solve(int n, int k, vector<int> &stalls)
{

    // Write your code here

    // We need to place cows in minimum distace . and minimum distance between all possible way return maximum
    sort(stalls.begin(), stalls.end());

    int mini = stalls[0], maxi = stalls[n - 1];

    int s = 1, e = maxi - mini; // for 2 cows we place them at extrem postions for max answer

    int ans = 0;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;

        if (canPlaceAllCows(mid, stalls, k))
        {
            ans = mid;
            s = mid + 1; // go for higer distance
        }
        else
            e = mid - 1;
    }

    return ans;
}