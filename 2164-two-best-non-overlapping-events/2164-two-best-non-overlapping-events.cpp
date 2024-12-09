// // class Solution {
// // public:
// //     int maxTwoEvents(vector<vector<int>>& events) {
// //         sort(events.begin(), events.end());
// //         vector<vector<int>> dp(events.size(), vector<int>(3, -1));
// //         return findEvents(events, 0, 0, dp);
// //     }
// //     int findEvents(vector<vector<int>>& events, int idx, int cnt,
// //                    vector<vector<int>>& dp) {
// //         if (cnt == 2 || idx >= events.size()) return 0;
// //         if (dp[idx][cnt] == -1) {
// //             int end = events[idx][1];
// //             int lo = idx + 1, hi = events.size() - 1;
// //             while (lo < hi) {
// //                 int mid = lo + ((hi - lo) >> 1);
// //                 if (events[mid][0] > end)
// //                     hi = mid;
// //                 else
// //                     lo = mid + 1;
// //             }
// //             int include =
// //                 events[idx][2] + (lo < events.size() && events[lo][0] > end
// //                                       ? findEvents(events, lo, cnt + 1, dp)
// //                                       : 0);
// //             int exclude = findEvents(events, idx + 1, cnt, dp);
// //             dp[idx][cnt] = max(include, exclude);
// //         }
// //         return dp[idx][cnt];
// //     }
// // };

// class Solution {
// public:
//     int maxTwoEvents(vector<vector<int>>& events) {
//         priority_queue<pair<int, int>, vector<pair<int, int>>,
//                        greater<pair<int, int>>>
//             pq;
//         sort(events.begin(), events.end());

//         int maxVal = 0, maxSum = 0;

//         for (auto& event : events) {
//             while (pq.size() && pq.top().first < event[0]) {
//                 maxVal = max(maxVal, pq.top().second);
//                 pq.pop();
//             }

//             maxSum = max(maxSum, maxVal + event[2]);
//             pq.push({event[1], event[2]});
//         }

//         return maxSum;
//     }
// };

class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        vector<array<int, 3>> times;
        for (auto& e : events) {
            times.push_back({e[0], 1, e[2]});
            times.push_back({e[1] + 1, 0, e[2]});
        }
        int ans = 0, maxValue = 0;
        sort(begin(times), end(times));
        for (auto& timeValue : times) {
            if (timeValue[1]) {
                ans = max(ans, timeValue[2] + maxValue);
            } else {
                maxValue = max(maxValue, timeValue[2]);
            }
        }
        return ans;
    }
};