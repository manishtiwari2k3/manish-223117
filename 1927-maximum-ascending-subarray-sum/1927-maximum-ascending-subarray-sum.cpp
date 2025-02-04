class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int maxSum = 0;

        for (int startIdx = 0; startIdx < nums.size(); startIdx++) {
            int currentSubarraySum = nums[startIdx];

            for (int endIdx = startIdx + 1;
                 endIdx < nums.size() && nums[endIdx] > nums[endIdx - 1];
                 endIdx++) {
                currentSubarraySum += nums[endIdx];
            }

            // Update maxSum if we find a larger ascending subarray sum
            maxSum = max(maxSum, currentSubarraySum);
        }

        return maxSum;
    }
};