#include <bits/stdc++.h>
using namespace std;
long long int atMostKsubstring(string s, int k)
{
    if (k < 0)
        return 0;

    int disCnt = 0;
    vector<int> freq(26, 0);

    int n = s.length();
    int i = 0, j = 0;

    long long ans = 0;

    while (j < n)
    {
        freq[s[j] - 'a']++;
        
        if (freq[s[j] - 'a'] == 1)
            disCnt++;

        while (i <= j && disCnt > k)
        {
            freq[s[i] - 'a']--;

            if (freq[s[i] - 'a'] == 0)
                disCnt--;

            i++;
        }

        ans += (j - i) + 1;

        j++;
    }

    return ans;
}

long long int substrCount(string s, int k)
{
    return atMostKsubstring(s, k) - atMostKsubstring(s, k - 1);
}

int main()
{
    cout << substrCount("ababc", 2) << endl;
    return 0;
}