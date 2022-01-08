#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 2;
int dp[N][N];

int LCS(string x, string y, int n, int m)
{
    if (n == 0 || m == 0)
        return 0;

    if (dp[n][m] != -1)
        return dp[n][m];

    if (x[n - 1] == y[m - 1])
        dp[n][m] = 1 + LCS(x, y, n - 1, m - 1);
    else
        dp[n][m] = max(LCS(x, y, n, m - 1), LCS(x, y, n - 1, m));

    return dp[n][m];
}

int main()
{
    memset(dp, -1, sizeof dp); // initialization of dp table

    string x, y;
    cin >> x >> y;
    cout << LCS(x, y, x.length(), y.length());
    return 0;
}