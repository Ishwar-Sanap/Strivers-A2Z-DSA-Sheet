#include<bits/stdc++.h>
using namespace std;

/*
Input: s = "(1+(2*3)+((8)/4))+1"
Output: 3
Explanation: Digit 8 is inside of 3 nested parentheses in the string.
*/
int maxDepth(string s) {

    int maxOpen = 0;
    int ocnt = 0;

    // As given string is Valid paranthesis string (VPC)
    for(char ch : s)
    {
        if(ch == '(') ocnt++;
        else if(ch == ')')ocnt--;

        maxOpen = max(maxOpen,ocnt);
    }
    return maxOpen;
        
}

int main()
{
    cout<<maxDepth("(1+(2*3)+((8)/4))+1");
    
    return 0;
}