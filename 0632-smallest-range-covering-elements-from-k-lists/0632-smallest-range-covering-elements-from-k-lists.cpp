// class Solution {
// public:
//     vector<int> smallestRange(vector<vector<int>>& nums) {
//         int k = nums.size();
//         vector<int> indices(k, 0);
//         vector<int> range = {0, INT_MAX};

//         while (true) {
//             int curMin = INT_MAX, curMax = INT_MIN, minListIndex = 0;

//             for (int i = 0; i < k; i++) {
//                 int currentElement = nums[i][indices[i]];

//                 if (currentElement < curMin) {
//                     curMin = currentElement;   
//                     minListIndex = i;
//                 }

//                 if (currentElement > curMax) {
//                     curMax = currentElement;
//                 }
//             }

//             if (curMax - curMin < range[1] - range[0]) {
//                 range[0] = curMin;
//                 range[1] = curMax;
//             }

//             if (++indices[minListIndex] == nums[minListIndex].size()) break;
//         }

//         return range;
//     }
// };


class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>, greater<>>
            pq;
        int maxVal = INT_MIN, rangeStart = 0, rangeEnd = INT_MAX;

        for (int i = 0; i < nums.size(); i++) {
            pq.push({nums[i][0], {i, 0}});
            maxVal = max(maxVal, nums[i][0]);
        }

        while (pq.size() == nums.size()) {
            auto [minVal, indices] = pq.top();
            pq.pop();
            int row = indices.first, col = indices.second;
            if (maxVal - minVal < rangeEnd - rangeStart) {
                rangeStart = minVal;
                rangeEnd = maxVal;
            }
            if (col + 1 < nums[row].size()) {
                int nextVal = nums[row][col + 1];
                pq.push({nextVal, {row, col + 1}});
                maxVal = max(maxVal, nextVal);
            }
        }

        return {rangeStart, rangeEnd};
    }
};