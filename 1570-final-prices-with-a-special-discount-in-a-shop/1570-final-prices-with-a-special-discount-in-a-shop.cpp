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
        vector<int> result = prices;

        stack<int> stack;

        for (int i = 0; i < prices.size(); i++) {
            while (!stack.empty() && prices[stack.top()] >= prices[i]) {
                result[stack.top()] -= prices[i];
                stack.pop();
            }
            stack.push(i);
        }

        return result;
    }
};