// // class Solution {
// // public:
// //     long long continuousSubarrays(vector<int>& nums) {
// //         map<int, int> freq;
// //         int left = 0, right = 0;
// //         int n = nums.size();
// //         long long count = 0; 

// //         while (right < n) {
// //             freq[nums[right]]++;

// //             while (freq.rbegin()->first - freq.begin()->first > 2) {
// //                 freq[nums[left]]--;
// //                 if (freq[nums[left]] == 0) {
// //                     freq.erase(nums[left]);
// //                 }
// //                 left++;
// //             }

// //             count += right - left + 1;
// //             right++;
// //         }

// //         return count;
// //     }
// // };

// class Solution {
// public:
//     long long continuousSubarrays(vector<int>& nums) {
//         int left = 0, right = 0;
//         long long count = 0;  
//         priority_queue<int, vector<int>, function<bool(int, int)>> minHeap(
//             [&nums](int a, int b) { return nums[a] > nums[b]; });
//         priority_queue<int, vector<int>, function<bool(int, int)>> maxHeap(
//             [&nums](int a, int b) { return nums[a] < nums[b]; });

//         while (right < nums.size()) {
//             minHeap.push(right);
//             maxHeap.push(right);

//             while (left < right &&
//                    nums[maxHeap.top()] - nums[minHeap.top()] > 2) {
//                 left++;

//                 while (!maxHeap.empty() && maxHeap.top() < left) {
//                     maxHeap.pop();
//                 }
//                 while (!minHeap.empty() && minHeap.top() < left) {
//                     minHeap.pop();
//                 }
//             }

//             count += right - left + 1;
//             right++;
//         }

//         return count;
//     }
// };


class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        deque<int> maxQ, minQ;
        int left = 0;
        long long count = 0;

        for (int right = 0; right < nums.size(); right++) {
            while (!maxQ.empty() && nums[maxQ.back()] < nums[right]) {
                maxQ.pop_back();
            }
            maxQ.push_back(right);

            while (!minQ.empty() && nums[minQ.back()] > nums[right]) {
                minQ.pop_back();
            }
            minQ.push_back(right);

            while (!maxQ.empty() && !minQ.empty() &&
                   nums[maxQ.front()] - nums[minQ.front()] > 2) {
                if (maxQ.front() < minQ.front()) {
                    left = maxQ.front() + 1;
                    maxQ.pop_front();
                } else {
                    left = minQ.front() + 1;
                    minQ.pop_front();
                }
            }

            count += right - left + 1;
        }
        return count;
    }
};