#include <bits/stdc++.h>
using namespace std;

/*
Input: strs = ["flower","flow","flight"]
Output: "fl"
*/

/*
str.substr (int pos, int len)

pos : Index of first character (default 0).
len : Number of characters in substring (Length of the sub-string.)

*/

// TC O(M * N)
string longestCommonPrefix(vector<string> &strs)
{
    int n = strs.size();
    int j = 0;
    int str1Len = strs[0].length();

    string res = "";
    while (j < str1Len)
    {
        int i = 1;
        for (i = 1; i < n; i++)
        {
            if (j >= strs[i].length() || (strs[i][j] != strs[0][j]))
                return res;
        }

        if (i == n)
            res += strs[0][j];

        j++;
    }

    return res;
}

// TC O(N(LogN) + M)
string longestCommonPrefix2(vector<string> &strs)
{
    int n = strs.size();
    sort(strs.begin(), strs.end());

    // Sort all the string according to alphabetical order.
    // longest common prefix should be same in every string if present
    // so we compare string1 and string n

    int n1 = strs[0].length();
    int n2 = strs[n - 1].length();

    int i = 0;
    while (i < n1 && i < n2)
    {
        if (strs[0][i] == strs[n - 1][i])
            i++;

        else
            break;
    }

    string ans = strs[0].substr(0, i);
    return ans;
}

int main()
{
    vector<string> strs = {"flower", "flow", "flight"};
    cout << longestCommonPrefix(strs) << endl;

    return 0;
}