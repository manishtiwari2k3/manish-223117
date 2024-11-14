// class Solution {
// public:
//     bool canDistribute(int x, vector<int>& quantities, int n) {
//         int j = 0;
//         int remaining = quantities[j];

//         for (int i = 0; i < n; i++) {
//             if (remaining <= x) {
//                 j++;
//                 if (j == quantities.size()) {
//                     return true;
//                 } else {
//                     remaining = quantities[j];
//                 }
//             } else {
//                 remaining -= x;
//             }
//         }
//         return false;
//     }
//     int minimizedMaximum(int n, vector<int>& quantities) {
//         int left = 0;
//         int right = *max_element(quantities.begin(), quantities.end());

//         while (left < right) {
//             int middle = (left + right) / 2;
//             if (canDistribute(middle, quantities, n)) {
//                 right = middle;
//             } else {
//                 left = middle + 1;
//             }
//         }
//         return left;
//     }
// };





class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int m = quantities.size()
        auto compareTypeStorePairs = [](pair<int, int>& a, pair<int, int>& b) {
            return (long long)a.first * b.second <
                   (long long)a.second * b.first;
        };

        vector<pair<int, int>> typeStorePairsArray;

        for (int i = 0; i < m; i++) {
            typeStorePairsArray.push_back({quantities[i], 1});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       decltype(compareTypeStorePairs)>
            typeStorePairs(typeStorePairsArray.begin(),
                           typeStorePairsArray.begin() + m);

        for (int i = 0; i < n - m; i++) {
            pair<int, int> pairWithMaxRatio = typeStorePairs.top();
            int totalQuantityOfType = pairWithMaxRatio.first;
            int storesAssignedToType = pairWithMaxRatio.second;
            typeStorePairs.pop();

            typeStorePairs.push(
                {totalQuantityOfType, storesAssignedToType + 1});
        }

        pair<int, int> pairWithMaxRatio = typeStorePairs.top();
        int totalQuantityOfType = pairWithMaxRatio.first;
        int storesAssignedToType = pairWithMaxRatio.second;

        return ceil((double)totalQuantityOfType / storesAssignedToType);
    }
};