#include<bits/stdc++.h>
using namespace std;

/*
arr = 3 9 -2 4 1 -7 2 6 -5 8 -3 -7 6 2 1
k = 5

output : 

*/
int subarraySum(vector<int>& nums, int k) {
        
        int n = nums.size();
        unordered_map<int,int>presum; /// it stores the presums and number of time it occures previously
        presum[0]=1;

       int sum = 0;
       int cnt = 0;

        for(int i = 0; i<n; i++)
        {
            sum += nums[i];

            int req = sum-k;
            
            if(presum.find(req) != presum.end())
                cnt += presum[req];
 
            presum[sum]++;
        }
        return cnt;
    }

int main()
{
    vector<int>arr = {3, 9 ,-2, 4, 1, -7, 2, 6, -5, 8 ,-3 ,-7, 6, 2, 1};
    cout<<subarraySum(arr , 5)<<endl;
    return 0;
}