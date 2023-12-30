#include <bits/stdc++.h>
using namespace std;
bool static comp(pair<int, char> p1, pair<int, char> p2)
{
    if (p1.first <= p2.first)
        return false;

    return true;
}
string frequencySort(string s)
{

    vector<pair<int, char>> freq(128, {0, 'a'});

    for (char ch : s)
    {
        int val = freq[ch].first;
        freq[ch] = {val + 1, ch};
    }

    // sort in decresing order of freq of the character
    sort(freq.begin(), freq.end(), comp);

    string res = "";

    for (int i = 0; i < 128; i++)
    {
        int cnt = freq[i].first;
        char ch = freq[i].second;

       res.append(cnt,ch); // 3 , e
    }
    return res;
}

// Using Bucket sort
string frequencySort2(string s)
{
    /*

        ex: trreeep
        bucket(5) 0    1     2       3       4 (freq)
                  ""  "tp"  "rr"  "eee""     ""
        */

    int n = s.size();
    string res = "";

    unordered_map<char, int> mp;
    for (char ch : s)
        mp[ch]++;

    vector<string> bucket(n + 1, "");

    // Putting characters into bucket
    for (auto pair : mp)
    {
        char ch = pair.first;
        int f = pair.second;

        bucket[f].append(f, ch); // 3 , e
    }

    for (int i = n; i >= 0; i--)
    {
        if (bucket[i].length() > 0)
        {
            res.append(bucket[i]);
        }
    }
    return res;
}
int main()
{
    cout<<frequencySort("trreeep")<<endl;
    return 0;
}