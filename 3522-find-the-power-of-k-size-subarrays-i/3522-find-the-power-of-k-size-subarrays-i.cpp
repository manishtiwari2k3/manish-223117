// // class Solution {
// // public:
// //     vector<int> resultsArray(vector<int>& nums, int k) {
// //         int length = nums.size();
// //         vector<int> result(length - k + 1);

// //         for (int start = 0; start <= length - k; start++) {
// //             bool isConsecutiveAndSorted = true;

// //             for (int index = start; index < start + k - 1; index++) {
// //                 if (nums[index + 1] != nums[index] + 1) {
// //                     isConsecutiveAndSorted = false;
// //                     break;
// //                 }
// //             }
// //             if (isConsecutiveAndSorted) {
// //                 result[start] = nums[start + k - 1];
// //             } else {
// //                 result[start] = -1;
// //             }
// //         }

// //         return result;
// //     }
// // };


// class Solution {
// public:
//     vector<int> resultsArray(vector<int>& nums, int k) {
//         int length = nums.size();
//         vector<int> result(length - k + 1, -1);
//         deque<int> indexDeque;

//         for (int currentIndex = 0; currentIndex < length; currentIndex++) {
//             if (!indexDeque.empty() &&
//                 indexDeque.front() < currentIndex - k + 1) {
//                 indexDeque.pop_front();
//             }

//             if (!indexDeque.empty() &&
//                 nums[currentIndex] != nums[currentIndex - 1] + 1) {
//                 indexDeque.clear();
//             }

//             indexDeque.push_back(currentIndex);

//             if (currentIndex >= k - 1) {
//                 if (indexDeque.size() == k) {
//                     result[currentIndex - k + 1] = nums[indexDeque.back()];
//                 } else {
//                     result[currentIndex - k + 1] = -1;
//                 }
//             }
//         }

//         return result;
//     }
// };


class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        if (k == 1) {
            return nums;
        }

        size_t length = nums.size();
        vector<int> result(length - k + 1, -1);  
        int consecutiveCount = 1;

        for (size_t index = 0; index < length - 1; index++) {
            if (nums[index] + 1 == nums[index + 1]) {
                consecutiveCount++;
            } else {
                consecutiveCount = 1;  
            }
            if (consecutiveCount >= k) {
                result[index - k + 2] = nums[index + 1];
            }
        }

        return result;
    }
};