#include <bits/stdc++.h>
using namespace std;

unordered_map<string, int> mp;

int solve(string s, int i, int j, bool isTrue)
{
    // base condition
    if (i > j)
        return false;
    if (i == j)
        return s[i] == 'T';
    else
        return s[i] == 'F';

    string temp;
    temp.append(to_string(i));
    temp.push_back(' ');
    temp.append(to_string(j));
    temp.push_back(' ');
    temp.append(to_string(isTrue));

    if (mp.find(temp) != mp.end())
    {
        return mp[temp];
    }

    int ans = 0;
    for (int k = i + 1; k <= j - 1; k += 2)
    {
        int lT = solve(s, i, k - 1, 1);
        int lF = solve(s, i, k - 1, 0);
        int rT = solve(s, k + 1, j, 1);
        int rF = solve(s, k + 1, j, 0);

        if (s[k] == '&')
        {
            if (isTrue == 1)
                ans = ans + (lT * rT);
            else
                ans = ans + (lF * rT) + (lT * rF) + (lF * rF);
        }
        else if (isTrue == '|')
        {
            if (isTrue == 1)
                ans = ans + (lT * rT) + (lT * rF) + (lF * rT);
            else
                ans = ans + (lF * rF);
        }
        else if (s[k] == '^')
        {
            if (isTrue == 1)
                ans = ans + (lT * rF) + (rT * lF);
            else
                ans = ans + (lT * rT) + (lF * rF);
        }
    }
    return mp[temp] = ans;
}

int main()
{
    mp.clear();

    string s;
    cin >> s;

    cout << solve(s, 0, 7, 1) << endl;
}

//  T|T&F^T