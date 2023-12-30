#include<bits/stdc++.h>
using namespace std;

/*
    Input  arr 3 5 8 15 19 x = 9
    output  index 3 (15)
*/



int lowerBound(vector<int> arr, int n, int x) {
	// Write your code here
	int s = 0 , e = n-1;

	int ans = n;

	// we have to find first smallest element whose value is greter than or equal to x
	while( s <= e)
	{
		int mid = s + (e-s)/2;

		if(arr[mid] < x)
			s = mid+1;
		
		else if(arr[mid] >= x)
		{
			ans = mid;
			e = mid-1;
		} 
	}	
	return ans;
}
