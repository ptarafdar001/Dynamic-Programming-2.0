#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int coin[n];
    for (int i = 0; i < n; i++)
        cin >> coin[i];
    int sum;
    cin >> sum;

    int dp[n + 1][sum + 1];

    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < sum + 1; j++)
        {
            if (i == 0)
                dp[i][j] = 0;
            if (j == 0)
                dp[i][j] = 1;
        }
    }

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {
            if (coin[i - 1] <= j)
                dp[i][j] = dp[i][j - coin[i - 1]] + dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    cout << dp[n][sum] << endl;
    return 0;
}

/*  
input:
    3             
    1 2 3
    5             
output:
    5 ways
*/