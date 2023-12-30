#include <bits/stdc++.h>
using namespace std;

/*You are given a sorted array ‘arr’ of length ‘n’, which contains positive integer positions of ‘n’ gas stations on the X-axis.
You are also given an integer ‘k’.
You have to place 'k' new gas stations on the X-axis.
You can place them anywhere on the non-negative side of the X-axis, even on non-integer positions.
Let 'dist' be the maximum value of the distance between adjacent gas stations after adding 'k' new gas stations.

Find the minimum value of dist.
Example:
Input: ‘n' = 7 , ‘k’=6, ‘arr’ = {1,2,3,4,5,6,7}.

Answer: 0.5

*/
/*
double minimiseMaxDistance(vector<int> &arr, int k)
{
    // Write your code here.

    int n = arr.size();
    long double ans = -1;

    vector<int> howMany(n - 1, 0); // for getting minimu value we can place new gas station between give postion
    while (k >= 1)                 // place every gas station one by one
    {
        int maxiIndex = -1;
        long double maxVal = -1;
        for (int i = 0; i < n - 1; i++) // find the maximum differece where we can place new gas staiton
        {
            long double diff = (long double)(arr[i + 1]) - arr[i];

            long double sectionLen = (long double)(diff) / (howMany[i] + 1);

            if (sectionLen > maxVal)
            {
                maxVal = sectionLen;
                maxiIndex = i;
            }
        }

        // Place the gas station at maximum section length
        howMany[maxiIndex]++;
        k--;
    }

   
    for (int i = 0; i < n - 1; i++)
    {
        long double diff = (long double)(arr[i + 1]) - (long double)arr[i];
        long double sectionLen = (long double)diff / (howMany[i] + 1);

        ans = max(ans, sectionLen);
    }

    // cout<<ans<<endl;

    return ans;
}
*/

double minimiseMaxDistance(vector<int> &arr, int k)
{
    // Write your code here.

    int n = arr.size();
    long double ans = -1;
	vector<int> howMany(n - 1, 0);

	priority_queue< pair<long double , int> > pq;

	for (int i = 0; i < n - 1; i++) // find the maximum differece where we can place new gas staiton
        {
            long double diff = (long double)(arr[i + 1]) - arr[i];
           pq.push({diff,i});
        }

    while (k >= 1)                 // place every gas station one by one
    {
        int secIndex = pq.top().second ;
		long double maxValue = pq.top().first;
	
        // Place the gas station at maximum section length
        howMany[secIndex]++;

		long double sectionLen = (long double) (arr[secIndex+1] -  arr[secIndex]) /(long double) (howMany[secIndex] + 1);

		pq.pop(); // removing maximum differ as we place one gas station in between them
		
		// add new section length
		pq.push({sectionLen , secIndex});
		
        k--;
    }


    return pq.top().first;
}
int main()
{
    vector<int> arr = {1, 13, 17, 24};

    cout << minimiseMaxDistance(arr, 3);

    return 0;
}