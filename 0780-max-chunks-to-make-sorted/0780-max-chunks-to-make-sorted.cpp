// // class Solution {
// // public:
// //     int maxChunksToSorted(vector<int>& arr) {
// //         int n = arr.size();
// //         vector<int> prefixMax = arr;
// //         vector<int> suffixMin = arr;

// //         for (int i = 1; i < n; i++) {
// //             prefixMax[i] = max(prefixMax[i - 1], prefixMax[i]);
// //         }

// //         for (int i = n - 2; i >= 0; i--) {
// //             suffixMin[i] = min(suffixMin[i + 1], suffixMin[i]);
// //         }

// //         int chunks = 0;
// //         for (int i = 0; i < n; i++) {
// //             if (i == 0 || suffixMin[i] > prefixMax[i - 1]) chunks++;
// //         }

// //         return chunks;
// //     }
// // };


// class Solution {
// public:
//     int maxChunksToSorted(vector<int>& arr) {
//         int n = arr.size();
//         int chunks = 0, prefixSum = 0, sortedPrefixSum = 0;

//         for (int i = 0; i < n; i++) {
//             prefixSum += arr[i];
//             sortedPrefixSum += i;

//             if (prefixSum == sortedPrefixSum) {
//                 chunks++;
//             }
//         }
//         return chunks;
//     }
// };

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        stack<int> monotonicStack;
        for (int i = 0; i < n; i++) {
            if (monotonicStack.empty() || arr[i] > monotonicStack.top()) {
                monotonicStack.push(arr[i]);
            } else {
                int maxElement = monotonicStack.top();
                while (!monotonicStack.empty() &&
                       arr[i] < monotonicStack.top()) {
                    monotonicStack.pop();
                }
                monotonicStack.push(maxElement);
            }
        }
        return monotonicStack.size();
    }
};