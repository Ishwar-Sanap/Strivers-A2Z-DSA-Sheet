#include<bits/stdc++.h>
using namespace std;

int largestElement(vector<int> &arr) 
{
    // Write your code here.

    int maxi = INT_MIN;
    for(int ele : arr)
    {
        if(ele > maxi)
            maxi = ele;
    }
    return maxi;
}

int main()
{
    vector<int>arr = {-8,5,6,5,6,4,8};
    cout<< largestElement(arr);
    
    return 0;
}