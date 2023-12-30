#include<iostream>
using namespace std;

/*
Given an array A of N elements. Find the majority element in the array. 
A majority element in an array A of size N is an 
element that appears strictly more than N/2 times in the array.
*/

// By using the Morries votting algorithm 
/*
     the count becomes 0 as the occurrence of Element and
      the occurrence of the other elements are the same.
      So, they canceled each other. This is how the process works. 
      The element with the most occurrence will remain and the rest will cancel themselves.
*/
int majorityElement(int a[], int size)
{

    // your code here
    int ele = a[0], cnt = 0;

    int n = size;

    int i = 0;

    while (i < n)
    {
        if (ele == a[i])
            cnt++;
        else
            cnt--;

        if (cnt == 0)
        {
            ele = a[i];
            cnt = 1;
        }
        i++;
    }

    int elecnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == ele)
            elecnt++;
    }

    if (elecnt > n / 2)
        return ele;
    return -1;
}

int main()
{
    int arr[] = {3,2,2,1,2};
    cout<< majorityElement(arr ,5 )<<endl;

    return 0;
}