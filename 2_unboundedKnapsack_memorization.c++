#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp(101, vector<int>(1001));

int knapsack(vector<int> wt, vector<int> val, int n, int w)
{
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < w + 1; j++)
        {
            if (n == 0 || w == 0)
                dp[i][j] = 0;
            else
                dp[i][j] = -1;
        }
    }

    if (dp[n][w] != -1)
        return dp[n][w];

    if (wt[n - 1] <= w)
    {
        dp[n][w] = max(val[n - 1] + knapsack(wt, val, n, w - wt[n - 1]),
                       knapsack(wt, val, n - 1, w));
    }
    else
    {
        dp[n][w] = knapsack(wt, val, n - 1, w);
    }
    return dp[n][w];
}

int main()
{
    int n;
    cin >> n;
    vector<int> wt(n);
    for (int i = 0; i < n; i++)
        cin >> wt[i];
    vector<int> val(n);
    for (int i = 0; i < n; i++)
        cin >> val[i];
    int w;
    cin >> w;

    int max_profit = knapsack(wt, val, n, w);
    cout << max_profit;

    return 0;
}

/*
Test case:
    input:
        3
        5 10 15   -> wt[]
        10 30 20    -> val[]
        100          -> capacity of bag(w)
    output:
        300
*/