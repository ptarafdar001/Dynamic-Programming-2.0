#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> wt(n); // wt
    for (int i = 0; i < n; i++)
        cin >> wt[i];
    vector<int> val(n);
    for (int i = 0; i < n; i++)
        cin >> val[i];

    int w;
    cin >> w;
    /*
    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {
            if (wt[i - 1] <= j)
                dp[i][j] = max(val[i - 1] + dp[i][j - wt[i - 1]], dp[i - 1][j]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    cout << dp[n][sum] << endl;
*/
    // unbounded Knapsack - space optimization
    vector<int> dp(w + 1, 0);
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < w + 1; j++)
        {
            if (wt[i - 1] <= j)
                dp[j] = max(val[i - 1] + dp[j - wt[i - 1]], dp[j]);
        }
    }
    cout << dp[w];
    return 0;
}

/*  
Test case:
    input:
        4
        1 3 4 5   -> wait[]
        2 1 5 7    -> val[]
        7          -> w
    output:
        14
*/
