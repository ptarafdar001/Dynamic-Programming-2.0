#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 2;

vector<vector<int>> dp(N, vector<int>(N));

int coin_change(vector<int> coin, int sum, int n)
{
    if (n == 0)
        return 0;
    if (sum == 0)
        return 1;

    if (dp[n][sum] != -1)
        return dp[n][sum];

    if (coin[n - 1] <= sum)
        dp[n][sum] = dp[n][sum - coin[n - 1]] + dp[n - 1][sum];
    else
        dp[n][sum] = dp[n - 1][sum];

    return dp[n][sum];
}

int main()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (i == 0)
                dp[i][j] = 0;
            else if (j == 0)
                dp[i][j] = 1;
        }
    }

    int n;
    cin >> n;
    vector<int> coin(n);
    for (int i = 0; i < n; i++)
        cin >> coin[i];
    int sum;
    cin >> sum;

    cout << coin_change(coin, sum, n);
    return 0;
}