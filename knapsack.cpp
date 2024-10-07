#include <iostream>
#include <vector>
using namespace std;

// Function to solve 0/1 Knapsack using DP
int knapsack(int W, vector<int> &weights, vector<int> &values, int n) {
    // Create a 2D DP table to store results of subproblems
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    // Build the DP table in a bottom-up manner
    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (weights[i - 1] <= w) {
                // Option 1: Take the item (add value and reduce capacity)
                // Option 2: Don't take the item
                dp[i][w] = max(dp[i - 1][w], values[i - 1] + dp[i - 1][w - weights[i - 1]]);
            } else {
                // If the weight of the current item exceeds the capacity, skip it
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    // The last cell of the table contains the result: the maximum value
    return dp[n][W];
}

int main() {
    int n, W;
    
    // Input number of items and knapsack capacity
    cout << "Enter number of items: ";
    cin >> n;
    cout << "Enter knapsack capacity: ";
    cin >> W;

    vector<int> weights(n), values(n);
    
    // Input the weights and values of items
    cout << "Enter weights of the items: ";
    for (int i = 0; i < n; i++) cin >> weights[i];
    cout << "Enter values of the items: ";
    for (int i = 0; i < n; i++) cin >> values[i];

    // Call the knapsack function
    int max_value = knapsack(W, weights, values, n);

    // Output the result
    cout << "Maximum value in the knapsack: " << max_value << endl;

    return 0;
}
