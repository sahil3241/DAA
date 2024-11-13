#include <iostream>
#include <vector>
using namespace std;

int knapsack(int capacity, vector<int> &weights, vector<int> &values, int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int w = 0; w <= capacity; w++)
        {
            if (weights[i - 1] <= w)
            {
                dp[i][w] = max(dp[i - 1][w], values[i - 1] + dp[i - 1][w - weights[i - 1]]);
            }
            else
            {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][capacity];
}

int main()
{
    int n, capacity;
    cout << "Enter the number of items: ";
    cin >> n;
    cout << "Enter the capacity of the knapsack: ";
    cin >> capacity;

    vector<int> weights(n), values(n);
    cout << "Enter weights and values of each item:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> weights[i] >> values[i];
    }

    int maxValue = knapsack(capacity, weights, values, n);
    cout << "Maximum value in the knapsack: " << maxValue << endl;

    return 0;
}