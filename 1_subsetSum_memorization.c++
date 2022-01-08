#include <bits/stdc++.h>
using namespace std;

const int N = 10001;
int dp[N][N];

int subsetSum(int arr[], int n, int sum)
{

    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < sum + 1; j++)
        {
            if (i == 0)
                dp[i][j] = 0;
            if (j == 0)
                dp[i][j] = 1;

            if (i != 0 and j != 0)
                dp[i][j] = -1;
        }
    }

    if (dp[n][sum] != -1)
        return dp[n][sum];

    if (arr[n - 1] <= sum)
    {
        dp[n][sum] = subsetSum(arr, n - 1, sum - arr[n - 1]) || subsetSum(arr, n - 1, sum);
    }
    else
    {
        dp[n][sum] = subsetSum(arr, n - 1, sum);
    }

    return dp[n][sum];
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int sum;
    cin >> sum;

    cout << subsetSum(arr, n, sum);
}

/*  
Test case:
    input:
        5              <- arr size
        2 4 3 5 8
        11             <- target sum
    output:
        1 or 0
*/
