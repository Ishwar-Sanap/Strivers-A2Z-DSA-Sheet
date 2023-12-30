
/*
You have N books, each with A[i] number of pages. M students need to be allocated contiguous books, with each student getting at least one book.
Out of all the permutations, the goal is to find the permutation where the maximum number of pages allotted to a student should be minimum, out of all possible permutations.

Note: Return -1 if a valid assignment is not possible, and allotment should be in contiguous order (see the explanation for better understanding).

Input
5 4
25 46 28 49 24
Output :
71

All possible ways to allocate the ‘5’ books to '4' students are:

25 | 46 | 28 | 49 24 - the sum of all the pages of books allocated to students 1, 2, 3, and 4 are '25', '46', '28', and '73'. So the maximum is '73'.

25 | 46 | 28 49 | 24 - the sum of all the pages of books allocated to students 1, 2, 3, and 4 are '25', '46', '77', and '24'. So the maximum is '77'.

25 | 46 28 | 49 | 24 - the sum of all the pages of books allocated to students 1, 2, 3, and 4 are '25', '74', '49', and '24'. So the maximum is '74'.

25 46 | 28 | 49 | 24 - the sum of all the pages of books allocated to students 1, 2, 3, and 4 are '71', '28', '49', and '24'. So the maximum is '71'.
*/

#include <bits/stdc++.h>
using namespace std;

int getAllocateBooks(int pages, int arr[], int n, int M)
{
    int allocatedPages = 0;
    int student = 1;

    for (int i = 0; i < n; i++)
    {
        if ((allocatedPages + arr[i]) <= pages)
        {
            allocatedPages += arr[i];
        }
        else
        {
            student++;
            allocatedPages = arr[i];
        }
    }

    return student;
}

// Pattern is    min(max)
int findPages(int arr[], int n, int M)
{
    // code here
    if (M > n)
        return -1;

    int sum = 0, maxi = arr[0];
    for (int i = 0; i < n; i++)
    {
        maxi = max(arr[i], maxi);
        sum += arr[i];
    }

    int s = maxi, e = sum;

    int ans = -1;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;

        int students = getAllocateBooks(mid, arr, n, M);

        if (students > M)
        {
            s = mid + 1; // increse the bookPages
        }
        else
        {
            ans = mid;
            e = mid - 1;
        }
    }

    return ans;

    // without ans varibale we can also get result uisng polarity concept by return s
    // see the screenshot
}