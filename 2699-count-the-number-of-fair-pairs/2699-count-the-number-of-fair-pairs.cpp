// class Solution {
// public:
//     long long lower_bound(vector<int>& nums, int low, int high, int element) {
//         while (low <= high) {
//             int mid = low + ((high - low) / 2);
//             if (nums[mid] >= element) {
//                 high = mid - 1;
//             } else
//                 low = mid + 1;
//         }
//         return low;
//     }
//     long long countFairPairs(vector<int>& nums, int lower, int upper) {
//         sort(nums.begin(), nums.end());
//         long long ans = 0;
//         for (int i = 0; i < nums.size(); i++) {
//             int low =
//                 lower_bound(nums, i + 1, nums.size() - 1, lower - nums[i]);
//             int high =
//                 lower_bound(nums, i + 1, nums.size() - 1, upper - nums[i] + 1);

//             ans += 1LL * (high - low);
//         }
//         return ans;
//     }
// };


class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        return lower_bound(nums, upper + 1) - lower_bound(nums, lower);
    }

private:
    long long lower_bound(vector<int>& nums, int value) {
        int left = 0, right = nums.size() - 1;
        long long result = 0;
        while (left < right) {
            int sum = nums[left] + nums[right];
            if (sum < value) {
                result += (right - left);
                left++;
            } else {
                right--;
            }
        }
        return result;
    }
};