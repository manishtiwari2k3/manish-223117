// // class Solution {
// // public:
// //     int shortestSubarray(vector<int>& nums, int k) {
// //         int len;
// //         int cnt;
// //         for(int i=0;i<nums.size();i++){
// //             len = 0;
// //             cnt = 0;
// //             for(int j=i;j<nums.size();j++){
// //                 len = len + nums[j];
// //                 if(len<=k){
// //                     cnt++;
// //                     if(len==k){
// //                         break;
// //                     }
// //                 }
// //             }
// //             // if(len!=k){
// //             //     return -1;
// //             // }
// //         }
// //         if(len!=k){
// //                 return -1;
// //             }
// //         return cnt;
// //     }
// // };

// class Solution {
// public:
//     int shortestSubarray(vector<int>& nums, int k) {
//         int n = nums.size();

//         int shortestSubarrayLength = INT_MAX;

//         long long cumulativeSum = 0;

//         priority_queue<pair<long long, int>, vector<pair<long long, int>>,
//                        greater<>>
//             prefixSumHeap;

//         for (int i = 0; i < n; i++) {
//             cumulativeSum += nums[i];

//             if (cumulativeSum >= k) {
//                 shortestSubarrayLength = min(shortestSubarrayLength, i + 1);
//             }

//             while (!prefixSumHeap.empty() &&
//                    cumulativeSum - prefixSumHeap.top().first >= k) {
//                 shortestSubarrayLength =
//                     min(shortestSubarrayLength, i - prefixSumHeap.top().second);
//                 prefixSumHeap.pop();
//             }

//             prefixSumHeap.emplace(cumulativeSum, i);
//         }

//         return shortestSubarrayLength == INT_MAX ? -1 : shortestSubarrayLength;
//     }
// };


class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();

        vector<pair<long long, int>> cumulativeSumStack;
        cumulativeSumStack.emplace_back(0LL, -1);

        long long runningCumulativeSum = 0;
        int shortestSubarrayLength = INT_MAX;

        for (int i = 0; i < n; i++) {
            runningCumulativeSum += nums[i];
            while (!cumulativeSumStack.empty() &&
                   runningCumulativeSum <= cumulativeSumStack.back().first) {
                cumulativeSumStack.pop_back();
            }

            cumulativeSumStack.emplace_back(runningCumulativeSum, i);

            int candidateIndex = findCandidateIndex(cumulativeSumStack,
                                                    runningCumulativeSum - k);
            if (candidateIndex != -1) {
                shortestSubarrayLength =
                    min(shortestSubarrayLength,
                        i - cumulativeSumStack[candidateIndex].second);
            }
        }
        return shortestSubarrayLength == INT_MAX ? -1 : shortestSubarrayLength;
    }

public:
    int findCandidateIndex(const vector<pair<long long, int>>& nums,
                           long long target) {
        int left = 0, right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid].first <= target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return right;
    }
};