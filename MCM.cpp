#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int MCM(vector<int>& p) {
    int n = p.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // dp[i][j] represents the minimum number of scalar multiplications needed to multiply matrix Ai...Aj.
    for (int len = 2; len < n; len++) {  // Length of the chain
        for (int i = 1; i < n - len + 1; i++) {  // Starting index
            int j = i + len - 1;  // Ending index
            dp[i][j] = INT_MAX;  // Initialize with a large value

            // Try every possible position for splitting the chain
            for (int k = i; k < j; k++) {
                int q = dp[i][k] + dp[k + 1][j] + p[i - 1] * p[k] * p[j];
                dp[i][j] = min(dp[i][j], q);
            }
        }
    }

    return dp[1][n - 1];  // Minimum number of multiplications for multiplying matrices A1...An
}

int main() {
    int n;
    cout << "Enter the number of matrices: ";
    cin >> n;
    vector<int> p(n);

    cout << "Enter the dimensions of matrices (p1, p2, ..., pn): ";
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    int result = MCM(p);
    cout << "Minimum number of multiplications: " << result << endl;

    return 0;
}
