#include <bits/stdc++.h>
using namespace std;

/*
    // Optimized approach
    In pascal triangle we can find any element using formula of ncr
    ex : row = 4 , col = 2    n = 4 , r = 2 == > 6    { 4 * 3 / 2 * 1 == 6}

    so for finding the nth row we apply same formula for each column



*/
int mod = 1e9 + 7;
vector<long long> nthRowOfPascalTriangle(int n)
{
    // code here

    vector<vector<long long>> temp;

    for (int i = 0; i < n; i++)
    {
        vector<long long> res(i + 1, 1);
        cout << "row : " << i << endl;
        for (int j = 1; j < res.size() - 1; j++)
        {
            long long sum = (temp[i - 1][j - 1] + temp[i - 1][j]) % mod;
            res[j] = sum;
        }
        if (i + 1 == n)
            return res;

        temp.push_back(res);
    }

    return {};
}

int ncr(int r , int c)
{
    int ans = 1;

    for(int i = 0; i<c; i++)
    {
        ans = ans * (r - i);
        ans = ans / (i+1);
    }
    return ans;
}
vector<int> nth_row_Optimized(int n)
{
    vector<int> res;

    for(int col = 0; col <n; col++)
    {
        int val = ncr(n-1 , col);
        res.push_back(val);
    }
    return res;
}


vector<vector<int>> OPgeneratePascale(int n)
{
    vector<vector<int>> res;

    for(int i = 0; i<n ; i++)
    {
        vector<int> temp(i+1 , 1);
        int val = 1;
        for(int col = 1; col<temp.size()-1; col++)   
        {
            val *= (i+1 - col);
            val /= col;

            temp[col] = val;
        }

        res.push_back(temp);
    }
    return res;
}
int main()
{
    // vector<long long> ret = nthRowOfPascalTriangle(5);
    // vector<int>ret = nth_row_Optimized(5);
    // for (int eel : ret)
    //     cout << " " << eel;

    
vector<vector<int>> ret = OPgeneratePascale(5);
for(vector<int>v : ret)
{
for(int ele : v)
    cout<<ele<<" ";

cout<<endl;

}
    return 0;
}