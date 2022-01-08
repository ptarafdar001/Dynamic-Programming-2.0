// Longest Repeating Subsequence
#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    cin >> str;

    int n = str.length();
    int dp[n + 1][n + 1];

    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (str[i - 1] == str[j - 1] && i != j) // here is only one change from lCS
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    cout << dp[n][n] << endl;
    return 0;
}