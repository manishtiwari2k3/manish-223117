// class Solution {
// public:
//     vector<int> finalPrices(vector<int>& prices) {
//         int n = prices.size();
//         vector<int> result = prices;

//         for (int i = 0; i < n; i++) {
//             for (int j = i + 1; j < n; j++) {
//                 if (prices[j] <= prices[i]) {
//                     result[i] = prices[i] - prices[j];
//                     break;
//                 }
//             }
//         }

//         return result;
//     }
// };


class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        // Create a copy of prices array to store discounted prices
        vector<int> result = prices;

        stack<int> stack;

        for (int i = 0; i < prices.size(); i++) {
            // Process items that can be discounted by current price
            while (!stack.empty() && prices[stack.top()] >= prices[i]) {
                // Apply discount to previous item using current price
                result[stack.top()] -= prices[i];
                stack.pop();
            }
            // Add current index to stack
            stack.push(i);
        }

        return result;
    }
};