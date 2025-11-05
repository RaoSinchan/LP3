#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to solve 0-1 Knapsack problem
int knapsack(int W, vector<int>& wt, vector<int>& val, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    // Build dp[][] table in bottom-up manner
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (wt[i - 1] <= w)
                dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    // The last cell contains the maximum profit
    return dp[n][W];
}

int main() {
    int n;
    cout << "Enter number of items: ";
    cin >> n;

    vector<int> val(n), wt(n);

    cout << "Enter value and weight of each item:\n";
    for (int i = 0; i < n; i++) {
        cin >> val[i] >> wt[i];
    }

    int W;
    cout << "Enter capacity of knapsack: ";
    cin >> W;

    int maxVal = knapsack(W, wt, val, n);
    cout << "\nMaximum total value in knapsack = " << maxVal << endl;

    return 0;
}
