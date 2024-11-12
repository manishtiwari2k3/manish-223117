// class Solution {
// public:
//     vector<int> maximumBeauty(vector<vector<int>>& items,
//                               vector<int>& queries) {
//         vector<int> ans(queries.size());

//         sort(items.begin(), items.end(),
//              [](vector<int>& a, vector<int>& b) { return a[0] < b[0]; });

//         int maxBeauty = items[0][1];
//         for (int i = 0; i < items.size(); i++) {
//             maxBeauty = max(maxBeauty, items[i][1]);
//             items[i][1] = maxBeauty;
//         }

//         for (int i = 0; i < queries.size(); i++) {
//             ans[i] = binarySearch(items, queries[i]);
//         }

//         return ans;
//     }

//     int binarySearch(vector<vector<int>>& items, int targetPrice) {
//         int left = 0;
//         int right = items.size() - 1;
//         int maxBeauty = 0;
//         while (left <= right) {
//             int mid = (left + right) / 2;
//             if (items[mid][0] > targetPrice) {
//                 right = mid - 1;
//             } else {
//                 maxBeauty = max(maxBeauty, items[mid][1]);
//                 left = mid + 1;
//             }
//         }
//         return maxBeauty;
//     }
// };



class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items,
                              vector<int>& queries) {
        vector<int> ans(queries.size());
        sort(items.begin(), items.end(),
             [](vector<int>& a, vector<int>& b) { return a[0] < b[0]; });

        vector<vector<int>> queriesWithIndices(queries.size(), vector<int>(2));

        for (int i = 0; i < queries.size(); i++) {
            queriesWithIndices[i][0] = queries[i];
            queriesWithIndices[i][1] = i;
        }

        sort(queriesWithIndices.begin(), queriesWithIndices.end(),
             [](vector<int>& a, vector<int>& b) { return a[0] < b[0]; });

        int itemIndex = 0;
        int maxBeauty = 0;

        for (int i = 0; i < queries.size(); i++) {
            int query = queriesWithIndices[i][0];
            int originalIndex = queriesWithIndices[i][1];

            while (itemIndex < items.size() && items[itemIndex][0] <= query) {
                maxBeauty = max(maxBeauty, items[itemIndex][1]);
                itemIndex++;
            }

            ans[originalIndex] = maxBeauty;
        }
        return ans;
    }
};