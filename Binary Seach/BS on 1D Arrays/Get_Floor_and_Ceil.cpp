#include<bits/stdc++.h>
using namespace std;

/*
What is the floor of x?
The floor of x is the largest element in the array which is smaller than or equal to x( i.e. largest element in the array <= x).

What is the ceiling of x?
The ceiling of x is the smallest element in the array greater than or equal to x( i.e. smallest element in the array >= x).

Example 1:
Input Format: n = 6, arr[] ={3, 4, 4, 7, 8, 10}, x= 5
Result: 4 7
Explanation: The floor of 5 in the array is 4, and the ceiling of 5 in the array is 7.
*/
int getFloor(vector<int> &arr, int x)
{
	int s = 0, e= arr.size()-1;

	int ans = -1;

	while( s <= e)
	{
		int mid = s + (e-s)/2;

		if(arr[mid] > x)
			e = mid-1;
		
		else if(arr[mid] <= x)
		{
			ans = mid;
			s = mid+1;
		}
	}
	return ans == -1 ? -1 : arr[ans];
}

int getCeil(vector<int> &arr, int x)
{
	int s = 0, e= arr.size()-1;

	int ans = -1;

	while( s <= e)
	{
		int mid = s + (e-s)/2;

		if(arr[mid] >= x)
		{
			ans = mid;
			e = mid-1;
		}
		
		else if(arr[mid] <x)
			s = mid+1;

	}
	return ans == -1 ? -1 : arr[ans];
}

pair<int, int> getFloorAndCeil(vector<int> &a, int n, int x) {
	// Write your code here.

	pair<int,int> res;

	res.first = getFloor(a,x);
	res.second = getCeil(a,x);

	return res;
}