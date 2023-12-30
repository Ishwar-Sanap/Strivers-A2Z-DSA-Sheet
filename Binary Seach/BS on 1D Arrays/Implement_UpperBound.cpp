#include<bits/stdc++.h>
using namespace std;

/*

You are given a sorted array 'arr'containing 'n'integers and an integer 'x'.

Implement the 'upperBound' function to find the index of the upper bound of 'x' in the array.

Note:

The upper bound in a sorted array is the index of the first value that is greater than a given value.
If the greater value does not exist then the answer is 'n', Where 'n' is the size of the array.
We are using 0-based indexing.

Example:
Input: 'arr' = { 2,4,6,7} and 'x' = 5,
Output: 2 index (that is 6 is nearset  greter element than x )
*/



//Finding first greter element than x 
int upperBound(vector<int> &arr, int x, int n){
	// Write your code here.

	int s = 0 , e = n-1;

	int ans = n;

	while( s <= e)
	{
		int mid = s + (e-s)/2;

		if(arr[mid] <= x)
		 s = mid+1;

		else if(arr[mid] > x)
		{
			ans= mid;
			e = mid-1;
		}
	}	
	return ans;
}