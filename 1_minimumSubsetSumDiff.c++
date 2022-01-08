#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int range = accumulate(arr.begin(), arr.end(), 0);

    int dp[n + 1][range + 1];

    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < range + 1; j++)
        {
            if (i == 0)
                dp[i][j] = 0;
            if (j == 0)
                dp[i][j] = 1;
        }
    }
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < range + 1; j++)
        {
            if (arr[i - 1] <= j)
                dp[i][j] = dp[i - 1][j - arr[i - 1]] || dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    vector<int> lastRow(range + 1);
    for (int j = 0; j < lastRow.size(); j++)
    {
        if (dp[n][j] != 0)
            lastRow[j] = j;
    }

    int ans = INT_MAX;
    for (int i = 0; i < lastRow.size() / 2; i++)
    {
        ans = min(ans, range - (2 * lastRow[i]));
    }

    cout << ans << "\n";
    return 0;
}

/*
i/p:
    3
    1 2 7
o/p:
    4
*/