// class Solution {
// public:
//     int longestSquareStreak(vector<int>& nums) {
//         sort(nums.begin(), nums.end());

//         set<int> processedNumbers;

//         int longestStreak = 0;

//         for (int current : nums) {
//             if (processedNumbers.find(current) != processedNumbers.end())
//                 continue;

//             int streak = current;
//             int streakLength = 1;

            
//             while (true) {
//                 if ((long long)streak * (long long)streak > 1e5){
//                         break;
//                 }
//                 if (binarySearch(nums, streak * streak)) {
//                     streak *= streak;
//                     processedNumbers.insert(streak);
//                     streakLength++;
//                 } else {
//                     break;
//                 }
//             }

//             longestStreak = max(longestStreak, streakLength);
//         }

//         return longestStreak < 2 ? -1 : longestStreak;
//     }

// public:
//     bool binarySearch(vector<int>& nums, int target) {
//         if (target < 0) return false;

//         int left = 0;
//         int right = nums.size() - 1;

//         while (left <= right) {
//             int mid = left + (right - left) / 2;
//             if (nums[mid] == target) return true;
//             if (nums[mid] > target)
//                 right = mid - 1;
//             else
//                 left = mid + 1;
//         }

//         return false;
//     }
// };







class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        int longestStreak = 0;
        unordered_set<int> uniqueNumbers(nums.begin(), nums.end());
        for (int startNumber : nums) {
            int currentStreak = 0;
            long long current = startNumber;

            while (uniqueNumbers.find((int)current) != uniqueNumbers.end()) {
                currentStreak++;

                if (current * current > 1e5) break;

                current *= current;
            }

            longestStreak = max(longestStreak, currentStreak);
        }

        return longestStreak < 2 ? -1 : longestStreak;
    }
};