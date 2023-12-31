/*
The beauty of a string is the difference in frequencies between the most frequent and least frequent characters.

For example, the beauty of "abaacc" is 3 - 1 = 2.
Given a string s, return the sum of beauty of all of its substrings.



Example 1:

Input: s = "aabcb"
Output: 5
Explanation: The substrings with non-zero beauty are ["aab","aabc","aabcb","abcb","bcb"], each with beauty equal to 1.
*/

#include <bits/stdc++.h>
using namespace std;

int beautySum(string s)
{
    int n = s.length();
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        vector<int> freq(26, 0);

        for (int j = i; j < n; j++)
        {
            int idx = s[j] - 'a';
            freq[idx]++;

            int least = n, most = 0;

            for (int k = 0; k < 26; k++)
            {
                if (freq[k] == 0)
                    continue;

                most = max(most, freq[k]);
                least = min(least, freq[k]);
            }
            sum += most - least;
        }
    }
    return sum;
}
int main()
{
    cout << beautySum("aabcb");
    return 0;
}