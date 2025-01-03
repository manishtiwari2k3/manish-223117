// class Solution {
// public:
//     int waysToSplitArray(vector<int>& nums) {
//         int n = nums.size();
//         vector<long long> prefSum(n);
//         prefSum[0] = nums[0];

//         for (int i = 1; i < n; i++) {
//             prefSum[i] = prefSum[i - 1] + nums[i];
//         }

//         int count = 0;
//         for (int i = 0; i < n - 1; i++) {
//             long long leftSum = prefSum[i];
//             long long rightSum = prefSum[n - 1] - prefSum[i];

//             if (leftSum >= rightSum) {
//                 count++;
//             }
//         }

//         return count;
//     }
// };

class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        // Keep track of sum of elements on left and right sides
        long long leftSum = 0, rightSum = 0;

        // Initially all elements are on right side
        for (int num : nums) {
            rightSum += num;
        }

        int count = 0;
        // Try each possible split position
        for (int i = 0; i < nums.size() - 1; i++) {
            // Move current element from right to left side
            leftSum += nums[i];
            rightSum -= nums[i];

            // Check if this creates a valid split
            if (leftSum >= rightSum) {
                count++;
            }
        }

        return count;
    }
};