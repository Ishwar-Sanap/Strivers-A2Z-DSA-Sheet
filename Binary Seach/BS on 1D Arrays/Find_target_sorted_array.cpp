#include<bits/stdc++.h>
using namespace std;

/*
A real-life example of Binary Search:

Problem statement: Assume there is a dictionary and we have to find the word “raj”.

Method 1: One of the many ways is to check every possible page of the entire dictionary and see if we can find the word “raj”. This technique is known as linear search.
Basically, we can traverse from the first till the end to find the target value in the search space i.e. the entire dictionary in our example.

Method 2: In this case, we will optimize our search by using the property of a dictionary i.e. a dictionary is always in the sorted order.

We will first try to open the dictionary in such a way that it is roughly divided into two parts. 
Then, we will check the left page. Now, assume the words on the left page starts with ‘s’.
We can certainly say that our target word i.e. “raj” definitely comes before the words start with ‘s’. 
So, now, we need not search in the entire dictionary rather we will only search in the left half.
Now, we will do the same thing with the left half. First, we will divide it into 2 halves and then 
try to locate which half contains the word “raj”. Eventually, after certain steps, we will end up finding the word “raj”.
This is a typical real-life example of binary search. 

Note:
1)  Binary search is only applicable in a sorted search space. 
    The sorted search space does not necessarily have to be a sorted array.
    It can be anything but the search space must be sorted.

2 ) In binary search, we generally divide the search space into two equal halves 
    and then try to locate which half contains the target. According to that, we shrink the search space size.


Time Complexity Analysis : 
let assume n = 32

32 = 2 raise to 5

log(32) = 5*log(2)
log(32) = 5;

we say that for N size array we require only log(N) iterations in worst case.
Best case O(1)

Space complexiy == O(1)
*/

/*
N = 5
arr[] = {1 2 3 4 5} 
target = 4
output : 3 (index )
*/

int binarysearch(int arr[], int n, int target) {
    // code here
    
    int s = 0,  e = n-1;

    while(s <= e)
    {
        int mid = s + (e-s)/2; // To avoid the Integer overflow
        
        if(target == arr[mid]) return mid;
        else if(target > arr[mid]) s = mid+1;
        else e = mid-1;
    }
    return -1;
}

int binarysearchRecursive(int arr[] , int s , int e , int target)
{
    if(s > e) return -1;

    int mid = s + (e-s)/2;

    if(arr[mid] == target) return mid;

    if(target > arr[mid])
        return  binarysearchRecursive(arr,mid+1,e,target);

    else
        return binarysearchRecursive(arr,s,mid-1,target);
}

int main()
{
    int arr[] = {1, 2 ,3 ,4 ,5};

    cout<<binarysearch(arr,5,2);

    return 0;
}