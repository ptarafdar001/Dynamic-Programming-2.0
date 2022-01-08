//Minimum number of deletion in a string to make it a palindrome
// this question is same as
// Minimum number of insertion in a string to make it palisdrome

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

int longestPalinSubseq(string S, int n)
{
    // your code here
    string b = reverse(S);
    return LCS(S, b, n);
}

int minDeletions(string str, int n)
{
    //complete the function here
    return n - longestPalinSubseq(str, n);
}

int main()
{
    string s;
    cin >> s;

    cout << minDeletions(s, s.length()) << endl;

    return 0;
}

/*

Input:
    n = 7,
    str = "aebcbda"
Output:
    2
Explanation: We'll remove 'e' and
'd' and the string become "abcba".

â€‹Example 2:

Input:
    n = 3,
    str = "aba"
Output:
    0
Explanation: We don't remove any
character.
*/