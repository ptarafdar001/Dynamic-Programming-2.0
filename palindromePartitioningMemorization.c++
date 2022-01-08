#include <bits/stdc++.h>
#define int long long
using namespace std;

int dp[1001][1001];

bool isPalindrome(string str, int l, int h)
{
    // Keep comparing characters while they are same
    while (h > l)
    {
        if (str[l++] != str[h--])
        {
            return false;
        }
    }
    return true;
}

int solve(string str, int i, int j)
{
    if (i >= j)
        return 0;

    if (isPalindrome(str, i, j))
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    int MIN = INT_MAX;
    for (int k = i; k < j; k++)
    {
        //int temp = solve(str, i, k) + solve(str, k + 1, j) + 1;

        //farther optimization
        int left, right;
        //for left subtree
        if (dp[i][k] != -1)
            left = dp[i][k];
        else
        {
            left = solve(str, i, k);
            dp[i][k] = left;
        }
        // for right subtree
        if (dp[k + 1][j] != -1)
            right = dp[k + 1][j];
        else
        {
            right = solve(str, k + 1, j);
            dp[k + 1][j] = right;
        }
        int temp = 1 + left + right;
        if (temp < MIN)
            MIN = temp;
    }
    return dp[i][j] = MIN;
}

int32_t main()
{
    memset(dp, -1, sizeof(dp));

    string str;
    cin >> str;

    cout << solve(str, 0, str.length() - 1) << endl;
}