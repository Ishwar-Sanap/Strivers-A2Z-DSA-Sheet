#include <bits/stdc++.h>
using namespace std;

// As Row is sorted so we apply BS to find the no of 1 in tha row
// by using  col -  first occurace of 1

int getFirstOccrance(vector<int> row)
{
    int s = 0, e = row.size() - 1;

    while (s <= e)
    {
        int mid = s + (e - s) / 2;

        if (row[mid] == 0)
            s = mid + 1;

        else
            e = mid - 1;
    }

    return s;
}

// This algorithm takes n * log(m) Time complexity
int getRow(vector<vector<int>> &grid)
{
    int n = grid.size(), m = grid[0].size();
    int ans = -1;
    int maxCnt = -1;
    for (int i = 0; i < n; i++)
    {
        // count no of 1
        int cnt = m - getFirstOccrance(grid[i]);
        if (cnt > 0 && cnt > maxCnt)
        {
            ans = i;
            maxCnt = cnt;
        }
    }
    return ans;
}

// TC O(n + m)
int rowWithMax1s(vector<vector<int>> arr)
{
    int n = arr.size(), m = arr[0].size();
    int r = 0, c = m - 1; // poiting to top right corner
    int row_index_max_1 = -1;

    while (r < n && c >= 0)
    {
        if (arr[r][c] == 1)
        {
            row_index_max_1 = r;
            c--;
        }

        else
            r++;
    }
    return row_index_max_1;
}
int main()
{
    vector<vector<int>> grid = {
        {0, 0, 0, 0},
        {0, 0, 0, 1},
        {0, 1, 1, 1},
        {0, 0, 0, 1},
    };

    int r = rowWithMax1s(grid);
    cout << "Row with maximum ones " << r << endl;

    return 0;
}