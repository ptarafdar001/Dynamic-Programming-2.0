#include <bits/stdc++.h>
using namespace std;

//Minimum number of deletions and insertions.
int minOperations(string str1, string str2)
{
    // Your code goes here
    int n = str1.length();
    int m = str2.length();

    int dp[n + 1][m + 1];

    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < m + 1; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (str1[i - 1] == str2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    int LCS_len = dp[n][m];
    int del = n - LCS_len;
    int insert = m - LCS_len;

    return insert + del;
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;

    cout << minOperations(s1, s2) << endl;
    return 0;
}

/*
Input: 
    str1 = "heap", 
    str2 = "pea"
Output: 
    3
    
Explanation: 2 deletions and 1 insertion
p and h deleted from heap. Then, p is 
inserted at the beginning One thing to 
note, though p was required yet it was 
removed/deleted first from its position 
and then it is inserted to some other 
position. Thus, p contributes one to the 
deletion_count and one to the 
insertion_count.

Input : 
    str1 = "geeksforgeeks"
    str2 = "geeks"
Output: 
    8
Explanation: 8 insertions
*/