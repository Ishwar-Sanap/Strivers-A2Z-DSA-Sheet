#include <bits/stdc++.h>
using namespace std;

string expandFromCenter(string s, int i, int j)
{
    int n = s.length();
    while (i >= 0 && j < n && s[i] == s[j])
    {
        i--;
        j++;
    }
    // Ex: ebab if i and j poiting to a when loop end i points to e and j == n

    int len = j - i - 1;
    return s.substr(i + 1, len);
}
string longestPalindrome(string s)
{
    // pallidrom string can be of even or odd length;

    int n = s.length();
    if (n <= 1)
        return s;

    string res = "";

    for (int i = 0; i < n - 1; i++)
    {
        string odd = expandFromCenter(s, i, i);
        string even = expandFromCenter(s, i, i + 1);

        if (odd.length() > res.length())
            res = odd;

        if (even.length() > res.length())
            res = even;
    }
    return res;
}

int main()
{
    cout << longestPalindrome("cbabcpsiisps");
    return 0;
}