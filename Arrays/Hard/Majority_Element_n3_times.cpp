
#include <bits/stdc++.h>
using namespace std;

/*
Sample Input 1:
6
1 1 1 2 2 2
Sample Output 1:
1 2
*/

// Given array find the elements that appears more then n/3 times
// there is max 2 elements can be possible

// Algorithm is same as n/2 time element but take  2 elements
vector<int> majorityElement(vector<int> arr) {
	// Write your code here
	int n  = arr.size();

	int el1 = 0 , el2 = 0;
	int cnt1 = 0, cnt2 = 0;
	for(int i = 0; i<n; i++)
	{
		if(cnt1 == 0 && arr[i] != el2)
		{
			cnt1++;
			el1 = arr[i];
		}
		else if(cnt2 == 0 && arr[i] != el1)
		{
			cnt2++;
			el2 = arr[i];
		}
		else if(arr[i] == el1) cnt1++;
		else if(arr[i] == el2) cnt2++;
		else
		{
			cnt1--;
			cnt2--;
		}
	}

	cnt1 = 0 , cnt2 = 0;
	for(int i = 0; i<n; i++)
	{
		if(arr[i] == el1) cnt1++;
		if(arr[i] == el2) cnt2++;
	}

	vector<int>res;
	if(cnt1 > n/3) 
		res.push_back(el1);

	if(cnt2 > n/3) 
		res.push_back(el2);

	if(res.size() == 2 && el1 > el2) swap(res[0] , res[1]);

	return res;
	

}