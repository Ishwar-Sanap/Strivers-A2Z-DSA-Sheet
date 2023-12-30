#include <bits/stdc++.h>
using namespace std;
void sort012(int a[], int n)
{
    // code here

    // Low is poiting to the 0
    // hight is poiting to the 1
    int low = 0, high = n - 1;

    int i = 0;
    while (i <= high)   // Test Case [0,1,1,0]
    { 
        if (a[i] == 0)
        {
            swap(a[i], a[low]);
            low++;
            i++;
        }
        else if (a[i] == 1)
        {
            i++;
        }
        else
        {
            swap(a[i], a[high]);
            high--;
        }
    }
}
int main()
{
    int arr[] = {0,1,1,2,0,0,2,1};

    sort012(arr,8);

    for(int ele : arr)
        cout<<ele<<" ";

    
    return 0;
}