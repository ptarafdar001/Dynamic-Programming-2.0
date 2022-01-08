
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int subsetSum(int arr[], int n, int w)
    {
        vector<vector<int>> dp(n + 1, vector<int>(w + 1));

        for (int i = 0; i < n + 1; i++)
        {
            for (int j = 0; j < w + 1; j++)
            {
                if (i == 0)
                    dp[i][j] = 0;
                if (j == 0)
                    dp[i][j] = 1;
            }
        }

        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 1; j < w + 1; j++)
            {
                if (arr[i - 1] <= j)
                    dp[i][j] = dp[i - 1][j - arr[i - 1]] || dp[i - 1][j];
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        return dp[n][w];
    }

    int equalPartition(int N, int arr[])
    {
        // code here
        long long int sum = 0;
        for (int i = 0; i < N; i++)
        {
            sum = sum + arr[i];
        }

        if (sum % 2 != 0)
            return 0;
        else if (sum % 2 == 0)
            return subsetSum(arr, N, sum / 2);
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++)
            cin >> arr[i];

        Solution ob;
        if (ob.equalPartition(N, arr))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
} // } Driver Code Ends

/*
Input: N = 4
arr = {1, 5, 11, 5}
Output: YES
Explaination: 
The two parts are {1, 5, 5} and {11}.

Input: N = 3
arr = {1, 3, 5}
Output: NO
Explaination: This array can never be 
partitioned into two such parts.
*/