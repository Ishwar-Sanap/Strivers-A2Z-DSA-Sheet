#include<bits/stdc++.h>
using namespace std;

int SecondlargestElement(vector<int> &arr) 
{
    // Write your code here.
    int n = arr.size();

    int maxi1 = INT_MIN;
    int maxi2 = INT_MIN;

   for(int i = 0; i<n; i++)
    {
        if(arr[i] > maxi1)
        {
            maxi2 = maxi1;
            maxi1 = arr[i];
        }
        else if(arr[i] > maxi2 && arr[i] != maxi1 ) //arr[i] != maxi1  if array having more than one largest elements [ 8,8,8] 
        {
            maxi2 = arr[i];
        }
    }
    return maxi2;
}

int main()
{
    vector<int>arr = {8,8,8};
    cout<< SecondlargestElement(arr);
    
    return 0;
}