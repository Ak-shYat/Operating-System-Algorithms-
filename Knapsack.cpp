#include<bits/stdc++.h>
using namespace std;


// Function to solve the knapsack problem using dynamic programming
int solveTab(vector<int> weight, vector<int> value, int n, int W) {
    vector<vector<int>> dp(n, vector<int>(W + 1, 0));

    // Initialize the base case for the first item
    for (int w = weight[0]; w <= W; ++w) {
        if (weight[0] <= w) {
            dp[0][w] = value[0];
        } else {
            dp[0][w] = 0;
        }
    }

    // Fill in the DP table
    for (int i = 1; i < n; ++i) {
        for (int w = 0; w <= W; ++w) {
            int include = 0;
            if (weight[i] <= w) {
                include = value[i] + dp[i - 1][w - weight[i]];
            }
            int exclude = dp[i - 1][w];

            dp[i][w] = max(include, exclude);
        }
    }

    return dp[n - 1][W];
}

int main() {
    // Example usage
    vector<int> weight = {2, 3, 4};
    vector<int> value = {10, 15, 40};
    int n = weight.size();
    int maxWeight = 6;

    int result = solveTab(weight, value, n, maxWeight);
    cout << "Maximum value in the knapsack: " << result << endl;

    return 0;
}
