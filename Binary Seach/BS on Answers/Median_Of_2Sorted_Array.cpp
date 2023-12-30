#include <bits/stdc++.h>
using namespace std;

// Partitions containing how many element from arr1 and arr2 should be in left and right parts
double binarySearch(vector<int> &arr1, vector<int> &arr2, int partitions)
{
    int n1 = arr1.size(), n2 = arr2.size();

    int s = 0, e = n1;

    double ans = 0.0;
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
            if ((n1 + n2) % 2 == 0)
            {
                ans = ((double)(max(l1, l2) + min(r1, r2))) / 2.0; // find the mid
            }

            else
            {
                ans = max(l1, l2); // in left partions answere is possible due to odd elements
            }
            return ans;
        }

        if (l1 > r2) // ie arr2 containing smaller elemets so we need to minimize the count of array1 elements
            e = mid1 - 1;

        else
            s = mid1 + 1;
    }

    return ans;
}

double medianOfTwoSorted(vector<int> &arr1, vector<int> &arr2)
{
    int n1 = arr1.size(), n2 = arr2.size();

    // if n1 is bigger swap the arrays:
    // when we get n2 as null or n1 is higher then there is out of bound for n2 when calculating mid2 so change arr1 to arr2
    if (n1 > n2)
        return medianOfTwoSorted(arr2, arr1); 

    int partitions = 0;

    if ((n1 + n2) % 2 == 0)
        partitions = (n1 + n2) / 2;

    else
        partitions = ((n1 + n2) / 2) + 1;

    double ans = binarySearch(arr1, arr2, partitions);

    return ans;
}

int main()
{

    vector<int> arr1 = {1, 2, 3, 4};
    vector<int> arr2 = {3, 4, 5};

    cout << medianOfTwoSorted(arr1, arr2) << endl;

    return 0;
}