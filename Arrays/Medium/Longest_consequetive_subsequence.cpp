#include<bits/stdc++.h>
using namespace std;

/*
Input:
N = 7
a[] = {2,6,1,9,4,5,3}

Output:
6
Explanation:
The consecutive numbers here
are 1, 2, 3, 4, 5, 6. These 6 
numbers form the longest consecutive
subsquence.
*/

int findLongestConseqSubseq(int arr[], int N)
{
    // O(NlongN) Approach
    //   sort(arr , arr+N);

    //   int ans = 1;
    //   int len = 1;

    //   for(int i = 1; i<N; i++)
    //   {
    //       if(arr[i] == arr[i-1]+1) len++;
    //       else if(arr[i] == arr[i-1]) continue;
    //       else len = 1;

    //      ans = max(ans , len);
    //   }
    //   return ans;


    // All operations on the unordered_set done in constant time O(1)
    unordered_set<int> s(arr, arr + N);
    int ans = 0, len = 0;

    // O(N) Approach
    for (int ele : s)
    {
   
        // if ele is starting number then start counting next elements
        int start = ele;
        if (s.count(start - 1) == 0)
        {
            // Find the length of sequence from starting point
            while (s.count(start))
            {

                len++;
                start++;
            }
        }
        ans = max(ans, len);
        len = 0;
    }
    return ans;
}