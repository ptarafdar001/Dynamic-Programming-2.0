#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp(101, vector<int>(1001, -1));

int knapsack(vector<int> length, vector<int> price, int n, int w)
{
    if (n == 0 || w == 0)
        return 0;

    if (dp[n][w] != -1)
        return dp[n][w];

    if (length[n - 1] <= w)
    {
        dp[n][w] = max(price[n - 1] + knapsack(length, price, n, w - length[n - 1]),
                       knapsack(length, price, n - 1, w));
    }
    else
    {
        dp[n][w] = knapsack(length, price, n - 1, w);
    }
    return dp[n][w];
}

int main()
{
    int n;
    cin >> n;
    vector<int> price(n);
    for (int i = 0; i < n; i++)
        cin >> price[i];

    vector<int> length(n);
    for (int i = 0; i < n; i++)
        length[i] = i + 1;
    int max_len = n;
    int max_profit = knapsack(length, price, n, max_len);
    cout << max_profit;

    return 0;
}

/*
input
    8 
    1 5 8 9 10 17 17 20
output
    22
*/