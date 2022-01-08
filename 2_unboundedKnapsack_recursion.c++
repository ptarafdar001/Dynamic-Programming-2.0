#include <bits/stdc++.h>
using namespace std;

int knapsack(int wt[], int val[], int n, int w)
{
    if (n == 0 || w == 0)
        return 0;

    if (wt[n - 1] <= w)
    {
        return max(val[n - 1] + knapsack(wt, val, n, w - wt[n - 1]),
                   knapsack(wt, val, n - 1, w));
    }
    else
    {
        return knapsack(wt, val, n - 1, w);
    }
}

int main()
{
    int n;
    cin >> n;
    int wt[n];
    for (int i = 0; i < n; i++)
        cin >> wt[i];
    int val[n];
    for (int i = 0; i < n; i++)
        cin >> val[i];
    int w;
    cin >> w;

    int max_profit = knapsack(wt, val, n, w);
    cout << max_profit;

    return 0;
}

/*
Test case:
    input:
        3
        5 10 15   -> wt[]
        10 30 20    -> val[]
        100          -> capacity of bag(w)
    output:
        300
*/