// // class Solution {
// // public:
// //     int maximumBeauty(vector<int>& nums, int k) {
// //         sort(nums.begin(), nums.end());
// //         int maxBeauty = 0;

// //         for (int i = 0; i < nums.size(); i++) {
// //             int upperBound = findUpperBound(nums, nums[i] + 2 * k);
// //             maxBeauty = max(maxBeauty, upperBound - i + 1);
// //         }
// //         return maxBeauty;
// //     }

// // public:
// //     int findUpperBound(vector<int>& arr, int val) {
// //         int low = 0, high = arr.size() - 1, result = 0;

// //         while (low <= high) {
// //             int mid = low + (high - low) / 2;
// //             if (arr[mid] <= val) {
// //                 result = mid; 
// //                 low = mid + 1;
// //             } else {
// //                 high = mid - 1;  
// //             }
// //         }
// //         return result;
// //     }
// // };


// class Solution {
// public:
//     int maximumBeauty(vector<int>& nums, int k) {
//         sort(nums.begin(), nums.end());
//         int right = 0;
//         int maxBeauty = 1;

//         for (int left = 0; left < nums.size(); left++) {
//             while (right < nums.size() && nums[right] - nums[left] <= 2 * k) {
//                 right++;
//             }
//             maxBeauty = max(maxBeauty, right - left);
//         }
//         return maxBeauty;
//     }
// };

class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        if (nums.size() == 1) return 1;

        int maxBeauty = 0;
        int maxValue = 0;

        for (int num : nums) maxValue = max(maxValue, num);

        vector<int> count(maxValue + 1, 0);

        for (int num : nums) {
            count[max(num - k, 0)]++; 
            if (num + k + 1 <= maxValue)
                count[num + k + 1]--; 
        }

        int currentSum = 0;
        for (int val : count) {
            currentSum += val;
            maxBeauty = max(maxBeauty, currentSum);
        }

        return maxBeauty;
    }
};