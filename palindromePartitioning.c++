#include <bits/stdc++.h>
#define int long long
using namespace std;

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

    int MIN = INT_MAX;
    for (int k = i; k < j; k++)
    {
        int temp = solve(str, i, k) + solve(str, k + 1, j) + 1;

        if (temp < MIN)
            MIN = temp;
    }
    return MIN;
}

int32_t main()
{
    string str;
    cin >> str;

    cout << solve(str, 0, str.length() - 1) << endl;
}