#include <bits/stdc++.h>
using namespace std;

/*
Given two strings s and t, determine if they are isomorphic.
Two strings s and t are isomorphic if the characters in s can be replaced to get t.
All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.


Example 1:

Input: s = "egg", t = "add"
Output: true
Example 2:

Input: s = "foo", t = "bar"
Output: false
*/
bool isIsomorphic(string s, string t)
{
    int n = s.length();

    vector<int> mp(128, 0); // as ascii character are upto 127
    vector<int> mp2(128, 0);

    for (int i = 0; i < n; i++)
    {
        if (mp[s[i]] != mp2[t[i]])
            return false;

        // Assigning same number to both the characters
        mp[s[i]] = i + 1;
        mp2[t[i]] = i + 1;
    }
    return true;
}

bool isIsomorphic2(string s, string t)
{
    int n = s.length();

    // Mapping of the characters

    unordered_map<char, char> mp;
    unordered_map<char, char> mp2;

    for (int i = 0; i < n; i++)
    {
        if (mp.find(s[i]) != mp.end())
        {
            if (mp[s[i]] != t[i])
                return false;
        }

        if (mp2.find(t[i]) != mp2.end())
        {
            if (mp2[t[i]] != s[i])
                return false;
        }

        mp[s[i]] = t[i];
        mp2[t[i]] = s[i];
    }
    return true;
}