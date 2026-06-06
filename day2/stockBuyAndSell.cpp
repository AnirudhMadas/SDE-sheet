#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to calculate max profit using brute force
    int stockbuySell(vector<int>& prices) {
        // Initialize max profit to 0
        int maxProfit = 0;

        // Loop through each day as a potential buy day
        for(int i = 0; i < prices.size(); i++) {
            // Loop through each future day as a potential sell day
            for(int j = i + 1; j < prices.size(); j++) {
                // Calculate the profit
                int profit = prices[j] - prices[i];

                // Update max profit if this is higher
                maxProfit = max(maxProfit, profit);
            }
        }

        // Return the maximum profit
        return maxProfit;
    }

    // Function to calculate maximum profit using single pass
    int stockbuySell(vector<int>& prices) {
        // Initialize the minimum price to a large number
        int minPrice = INT_MAX;

        // Initialize the maximum profit to 0
        int maxProfit = 0;

        // Traverse each price in the array
        for (int price : prices) {
            // If current price is less than minPrice, update minPrice
            if (price < minPrice) {
                minPrice = price;
            }
            // Else calculate profit and update maxProfit if it's greater
            else {
                maxProfit = max(maxProfit, price - minPrice);
            }
        }

        // Return the maximum profit found
        return maxProfit;
    }
};

// Driver code
int main() {
    Solution sol;
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << "Max Profit: " << sol.stockbuySell(prices) << endl;
    return 0;
}
