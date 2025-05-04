#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to solve 0/1 Knapsack problem using dynamic programming
int knapsack(int W, vector<int>& wt, vector<int>& val, int n) {
    // dp[i][w] will store the maximum value that can be attained with
    // a knapsack capacity of w and using the first i items.
    vector<vector<int>> dp(n+1, vector<int>(W+1, 0));

    // Building the dp table in bottom-up manner
    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            // If the weight of the current item is less than or equal to the current capacity
            if (wt[i-1] <= w) {
                // Take the maximum of either taking or not taking the current item
                dp[i][w] = max(val[i-1] + dp[i-1][w - wt[i-1]], dp[i-1][w]);
            } else {
                // If the item cannot be included, just carry forward the value without including it
                dp[i][w] = dp[i-1][w];
            }
        }
    }
    
    // The last element in the dp table will contain the maximum value for the full knapsack
    return dp[n][W];
}

int main() {
    int n, W;
    cout << "Enter the number of items: ";
    cin >> n;

    cout << "Enter the maximum weight capacity of the knapsack: ";
    cin >> W;

    vector<int> val(n), wt(n);
    cout << "Enter the values of the items: ";
    for (int i = 0; i < n; i++) {
        cin >> val[i];
    }

    cout << "Enter the weights of the items: ";
    for (int i = 0; i < n; i++) {
        cin >> wt[i];
    }

    // Call the knapsack function and print the result
    int result = knapsack(W, wt, val, n);
    cout << "Maximum value in Knapsack = " << result << endl;

    return 0;
}
