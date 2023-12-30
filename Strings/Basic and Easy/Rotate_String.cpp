#include <bits/stdc++.h>
using namespace std;

/*
Given two strings s and goal, return true if and only if s can become goal after some number of shifts on s.

A shift on s consists of moving the leftmost character of s to the rightmost position.

For example, if s = "abcde", then it will be "bcdea" after one shift.
 

Example 1:

Input: s = "abcde", goal = "cdeab"
Output: true
Example 2:

Input: s = "abcde", goal = "abced"
Output: false
*/

bool rotateString(string s, string goal)
{

    string merge = s + s;

    int n = merge.length();
    int g = goal.length();

    if (g != s.length())
        return false;

    // Now check goal is present in merge string
    int i = 0;
    while (i < n)
    {
        int curr = i, j = 0;

        while (curr < n && j < g && merge[curr] == goal[j])
        {
            curr++;
            j++;
        }

        if (j == g)
            return true;

        i++;
    }
    return false;
}