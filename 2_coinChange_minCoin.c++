#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> coin(n);
    for (int i = 0; i < n; i++)
        cin >> coin[i];
    int sum;
    cin >> sum;

    vector<vector<int>> dp(n + 1, vector<int>(sum + 1));
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < sum + 1; j++)
        {
            if (j == 0)
                dp[i][j] = 0;

            if (i == 0)
                dp[i][j] = INT_MAX - 1;
        }
    }
    for (int k = 1; k < sum + 1; k++)
    {
        if (k % coin[0] != 0)
            dp[1][k] = INT_MAX - 1;
        else
            dp[1][k] = k / coin[0];
    }

    for (int i = 2; i < n + 1; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {
            if (coin[i - 1] <= j)
                dp[i][j] = min(1 + dp[i][j - coin[i - 1]], dp[i - 1][j]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    if (dp[n][sum] < INT_MAX - 1)
        cout << dp[n][sum] << endl;
    else
        cout << -1 << endl;
    return 0;
}