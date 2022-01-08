#include <bits/stdc++.h>
using namespace std;

int LCS(string s1, string s2, int n)
{
    int dp[n + 1][n + 1];

    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (s1[i - 1] == s2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    return dp[n][n];
}
string reverse(string str)
{
    string newstr;
    for (int i = str.length() - 1; i >= 0; i--)
        newstr.push_back(str[i]);

    return newstr;
}

int longestPalinSubseq(string S)
{
    // your code here
    int n = S.length();
    string b = reverse(S);
    return LCS(S, b, n);
}

int main()
{
    string s;
    cin >> s;
    cout << longestPalinSubseq(s) << endl;
}

/*
Input:
    S = "bbabcbcab"
Output:
     7
Explanation: Subsequence "babcbab" is the
longest subsequence which is also a palindrome.

Input: 
    S = "abcd"
Output: 
    1
Explanation: "a", "b", "c" and "d" are
palindromic and all have a length 1.
*/
