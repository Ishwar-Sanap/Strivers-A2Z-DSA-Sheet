#include<bits/stdc++.h>
using namespace std;

/*
Input: N = 5, arr[] = {2, 4, 1, 3, 5}
Output: 3

Explanation: The sequence 2, 4, 1, 3, 5 
has three inversions (2, 1), (4, 1), (4, 3).

Two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j.
*/

long long res = 0;
void mergeTwoSortedArray(vector<int>&arr,int s,int mid ,int e)
{
    int idx1 = s ;    //pointing two 1st array
    int idx2 = mid+1; // pointing two 2nd array

    vector<int>temp;
    while(idx1 <= mid && idx2 <= e)
    {
        if(arr[idx1] > arr[idx2] )
        {
            temp.push_back(arr[idx2]);

            res += mid - idx1 +1;
            idx2++;
        }
        else
        {
            temp.push_back(arr[idx1]);
            idx1++;
        }
    }

    while(idx1 <= mid)
    {
        temp.push_back(arr[idx1]);
        idx1++;
    }

    while(idx2 <= e)
    {
        temp.push_back(arr[idx2]);
        idx2++;
    }

    int i = s;
    for(int ele : temp)
    {
        arr[i] = ele;
        i++;
    }

} 
void mergeSort(vector<int>&arr , int s , int e )
{
    if(s>=e) return ;

    int mid = s + (e-s)/2;

    mergeSort(arr ,s,mid);
    mergeSort(arr ,mid+1,e);

    mergeTwoSortedArray(arr,s,mid , e);

}
int main()
{
    vector<int>arr = {2,3,6,4,3,7};

    mergeSort(arr,0,4 );
    cout<<res<<endl;

    return 0;
}