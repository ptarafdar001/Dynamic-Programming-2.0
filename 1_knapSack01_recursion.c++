#include <bits/stdc++.h>
using namespace std;

int knapsack(int wait[], int price[], int n, int capacity)
{
    if (n == 0 || capacity == 0)
        return 0;

    if (wait[n - 1] <= capacity)
    {
        return max(price[n - 1] + knapsack(wait, price, n - 1, capacity - wait[n - 1]),
                   knapsack(wait, price, n - 1, capacity));
    }
    else
    {
        return knapsack(wait, price, n - 1, capacity);
    }
}

int main()
{
    int n;
    cin >> n;
    int wait[n];
    for (int i = 0; i < n; i++)
        cin >> wait[i];
    int price[n];
    for (int i = 0; i < n; i++)
        cin >> price[i];
    int capacity;
    cin >> capacity;

    int max_profit = knapsack(wait, price, n, capacity);
    cout << max_profit;

    return 0;
}

/*
Test case:
    input:
        4
        1 3 4 5   -> wait[]
        1 4 5 7    -> price[]
        7          -> capacity of bag
    output:
        9
*/