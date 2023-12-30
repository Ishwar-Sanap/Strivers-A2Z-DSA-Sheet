#include <bits/stdc++.h>
using namespace std;

/*
Input: s = "(()())(())(()(()))"
Output: "()()()()(())"
Explanation:
The input string is "(()())(())(()(()))", with primitive decomposition "(()())" + "(())" + "(()(()))".
After removing outer parentheses of each part, this is "()()" + "()" + "()(())" = "()()()()(())".
*/
string removeOuterParentheses(string s)
{
    int ocnt = 0;
    string ans = "";
    for (char ch : s)
    {
        if (ch == '(')
        {
            ocnt++;
            if (ocnt > 1)
                ans += '(';
        }
        else
        {
            ocnt--;
            if (ocnt > 0)
                ans += ')';
        }
    }
    return ans;
}

int main()
{
    cout << removeOuterParentheses("(()())(())(()(()))") << endl;
    return 0;
}