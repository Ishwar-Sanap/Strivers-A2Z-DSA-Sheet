#include <bits/stdc++.h>
using namespace std;

/*
Input: s = "   the sky is blue     "
Output: "blue is sky the"

*/
string reverseWords(string s)
{

    int n = s.length();

    string res = "";

    int i = 0, j = n - 1;

    while (s[j] == ' ') // skipping the space at last
        j--;

    string word = "";

    while (i <= j)
    {
        if (s[i] == ' ')
        {
            if (word.length() > 0) res = " " + word + res;

            word = "";
        }

        else
            word += s[i];

        i++;
    }

    if (word.size() > 0)
        res = word + res;

    return res;
}

int main()
{
    cout << reverseWords("   the sky is blue     ") << endl;
    return 0;
}