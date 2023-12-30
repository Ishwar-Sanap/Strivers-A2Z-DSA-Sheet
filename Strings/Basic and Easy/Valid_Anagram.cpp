#include<bits/stdc++.h>
using namespace std;

/*
Given two strings s and t, return true if t is an anagram of s, and false otherwise.
An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

Example 1:

Input: s = "anagram", t = "nagaram"
Output: true
Example 2:

Input: s = "rat", t = "car"
Output: false
*/
bool isAnagram(string s, string t) 
{
    int freq[26] = {0};

    for(char ch : s)freq[ch-'a']++;

    for(char ch : t)freq[ch-'a']--;

    for(int f : freq)
        if(f != 0) return false;
        
    return true;
}

int main()
{
    cout<<isAnagram("rat","car")<<endl;
    return 0;
}