#include <bits/stdc++.h>
#define int long long
using namespace std;

int dp[1001][1001];

int solve(int arr[], int i, int j)
{
    if (i >= j)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    int MIN = INT_MAX;
    for (int k = i; k < j; k++)
    {
        int temp_ans = solve(arr, i, k) + solve(arr, k + 1, j) + (arr[i - 1] * arr[k] * arr[j]);
        if (temp_ans < MIN)
            MIN = temp_ans;
    }
    return dp[i][j] = MIN;
}

int32_t main()
{
    memset(dp, -1, sizeof(dp));

    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << solve(arr, 1, n - 1) << endl;
}