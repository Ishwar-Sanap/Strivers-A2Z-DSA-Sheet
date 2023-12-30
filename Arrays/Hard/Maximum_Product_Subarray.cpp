#include<bits/stdc++.h>
using namespace std;

/*
Input:
N = 5
Arr[] = {6, -3, -10, 0, 2}
Output: 180
*/

long long maxProduct(vector<int> arr, int n) {
    // code here
    
    long long ans  = arr[0];
    long long preProd = 1 , suffProd = 1;

    // Maximum product from array can be from either start or end
    for(int i = 0; i<n; i++)
    {
        preProd *= arr[i]; 
        suffProd *= arr[ n - i -1 ];
        
        ans = max({ans , preProd , suffProd });
        
        if(preProd == 0)preProd = 1;
        if(suffProd == 0)suffProd = 1;
    }
    
    return ans;
}

int main()
{
    vector<int> arr= {6, -3, -10, 0, 2};
    cout<<maxProduct(arr,5);
    
    return 0;
}