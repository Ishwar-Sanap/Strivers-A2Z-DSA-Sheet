/*
Input: n = 2, m = 9
Output: 3
Explanation: 3^2 = 9

*/
int NthRoot(int n, int m)
{
    // Code here.

    int s = 1, e = m;

    while (s <= e)
    {
        int mid = s + (e - s) / 2;

        long long val = 1;

        for (int i = 1; i <= n; i++)
        {
            val = val * (long long)mid;

            if (val > m)
            {
                break;
            }
        }

        if (val == m)
            return mid;

        else if (val > m)
            e = mid - 1;
        else
            s = mid + 1;
    }
    return -1;
}