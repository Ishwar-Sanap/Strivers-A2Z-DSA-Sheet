#include <bits/stdc++.h>
using namespace std;
/*
You are given a string num, representing a large integer. Return the largest-valued odd integer (as a string) that is a non-empty substring of num, or an empty string "" if no odd integer exists.

A substring is a contiguous sequence of characters within a string.



Example 1:

Input: num = "52"
Output: "5"
Explanation: The only non-empty substrings are "5", "2", and "52". "5" is the only odd number.
Example 2:

Input: num = "4206"
Output: ""
Explanation: There are no odd numbers in "4206".
*/

string largestOddNumber(string num)
{

    int i = 0, j = num.size() - 1;

    while (j >= 0)
    {
        int digit = num[j] - '0';
        if (digit % 2 != 0)
            break;
        j--;
    }

    string ans = num.substr(i, j - i + 1);
    return ans;
}