#include <bits/stdc++.h>
using namespace std;

int countSubsetSum(vector<int> arr, int sum, int n)
{

    vector<vector<int>> dp(n + 1, vector<int>(sum + 1));
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
            if (arr[i - 1] <= j)
                dp[i][j] = dp[i - 1][j - arr[i - 1]] + dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    return dp[n][sum];
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int diff;
    cin >> diff;

    int sum_subset1 = (diff + accumulate(arr.begin(), arr.end(), 0)) / 2;

    cout << countSubsetSum(arr, sum_subset1, n) << endl;
    return 0;
}

/*
input:
4
1 1 3 4
1
output:
3
*/