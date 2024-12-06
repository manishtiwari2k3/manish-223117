// class Solution {
// public:
//     int maxCount(vector<int>& banned, int n, int maxSum) {
//         sort(banned.begin(), banned.end());

//         int count = 0;

//         for (int num = 1; num <= n; num++) {
//             if (customBinarySearch(banned, num)) continue;

//             maxSum -= num;

//             if (maxSum < 0) break;

//             count++;
//         }
//         return count;
//     }

// public:
//     bool customBinarySearch(vector<int>& arr, int target) {
//         int left = 0;
//         int right = arr.size() - 1;

//         while (left <= right) {
//             int mid = left + (right - left) / 2;

//             if (arr[mid] == target) return true;

//             if (arr[mid] > target) {
//                 right = mid - 1;
//             } else {
//                 left = mid + 1;
//             }
//         }
//         return false;
//     }
// };


class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        sort(banned.begin(), banned.end());

        int bannedIdx = 0, count = 0;

        for (int num = 1; num <= n && maxSum >= 0; num++) {
            if (bannedIdx < banned.size() && banned[bannedIdx] == num) {
                while (bannedIdx < banned.size() && banned[bannedIdx] == num) {
                    bannedIdx++;
                }
            } else {
                maxSum -= num;
                if (maxSum >= 0) {
                    count++;
                }
            }
        }
        return count;
    }
};