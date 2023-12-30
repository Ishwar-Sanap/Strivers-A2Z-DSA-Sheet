#include <bits/stdc++.h>
using namespace std;
// Partitions containing how many element from arr1 and arr2 should be in left and right parts
int binarySearch(int arr1[], int arr2[], int n1, int n2, int k)
{
    int partitions = k;

    int s = max(0, k - n2); // at lest we need to pick k-n2 elements from arr1
    int e = min(k, n1);     // we only need to pick k elements
    int ans = 0;

    while (s <= e)
    {
        int l1 = INT_MIN, r1 = INT_MAX;
        int l2 = INT_MIN, r2 = INT_MAX;

        int mid1 = s + (e - s) / 2;
        int mid2 = partitions - mid1;

        if (mid1 >= 1)
            l1 = arr1[mid1 - 1];
        if (mid1 < n1)
            r1 = arr1[mid1];

        if (mid2 >= 1)
            l2 = arr2[mid2 - 1];
        if (mid2 < n2)
            r2 = arr2[mid2];

        if (l1 <= r2 && l2 <= r1) // got the answer
        {

            ans = max(l1, l2); // in left partions answere is possible due to we partition array at k

            return ans;
        }

        if (l1 > r2) // ie arr2 containing smaller elemets so we need to minimize the count of array1 elements
            e = mid1 - 1;

        else
            s = mid1 + 1;
    }

    return ans;
}
int kthElement(int arr1[], int arr2[], int n1, int n2, int k)
{

    // if n1 is bigger swap the arrays:
    // when we get n2 as null or n1 is higher then there is out of bound for n2 when calculating mid2 so change arr1 to arr2
    if (n1 > n2)
        return kthElement(arr2, arr1, n2, n1, k);

    int ans = binarySearch(arr1, arr2, n1, n2, k);

    return ans;
}
int main()
{
    int arr1[] = {4, 5, 7};
    int arr2[] = {2, 4, 5};

    cout << kthElement(arr1, arr2, 3, 3, 6) << endl;
    return 0;
}