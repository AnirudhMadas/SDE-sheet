#include <bits/stdc++.h>
using namespace std;

// Solution class to implement memoization approach
class Solution {
public:
    // Function to find minimum coins
    int coinChange(vector<int>& coins, int amount) {
        // Creating dp array initialized with -2 
        // (-2 means not calculated yet)
        vector<int> dp(amount + 1, -2);

        // Calling helper function
        return helper(coins, amount, dp);
    }

private:
    // Helper recursive function
    int helper(vector<int>& coins, int rem, vector<int>& dp) {
        // If remaining amount is zero
        if (rem == 0) return 0;

        // If remaining amount is negative
        if (rem < 0) return -1;

        // If already computed
        if (dp[rem] != -2) return dp[rem];

        // Initialize minimum with large value
        int mini = INT_MAX;

        // Try every coin
        for (int coin : coins) {
            // Recursive call
            int res = helper(coins, rem - coin, dp);

            // If result is valid
            if (res >= 0 && res < mini)
                mini = 1 + res;
        }

        // Store result in dp
        dp[rem] = (mini == INT_MAX) ? -1 : mini;
        return dp[rem];
    }

    //tabulation approach
    // Function to find minimum coins
    int coinChange1(vector<int>& coins, int amount) {
        // Creating dp array of size amount+1
        vector<int> dp(amount + 1, INT_MAX);

        // Base case: dp[0] = 0
        dp[0] = 0;

        // Loop through all amounts from 1 to amount
        for (int i = 1; i <= amount; i++) {
            // Try each coin
            for (int coin : coins) {
                // If coin can be used
                if (i - coin >= 0 && dp[i - coin] != INT_MAX) {
                    // Update dp[i] with minimum coins
                    dp[i] = min(dp[i], 1 + dp[i - coin]);
                }
            }
        }

        // If dp[amount] is still infinity, return -1
        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }

};

// Driver function
int main() {
    vector<int> coins = {1, 2, 5};
    int amount = 11;

    Solution obj;
    cout << obj.coinChange(coins, amount) << endl;
    return 0;
}
