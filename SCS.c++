#include <bits/stdc++.h>
using namespace std;

int LCS(string X, string Y, int n, int m)
{

    int dp[n + 1][m + 1];

    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < m + 1; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (X[i - 1] == Y[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[n][m];
}
int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    //length of sortest common supersequence
    cout << s1.length() + s2.length() - LCS(s1, s2, s1.length(), s2.length()) << endl;
    return 0;
}