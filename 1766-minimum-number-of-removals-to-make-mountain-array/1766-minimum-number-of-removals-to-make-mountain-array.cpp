// class Solution {
// public:
//     int minimumMountainRemovals(vector<int>& nums) {
//         int N = nums.size();

//         vector<int> lisLength(N , 1);
//         vector<int> ldsLength(N, 1);
//         for (int i = 0; i < N; i++) {
//             for (int j = i - 1; j >= 0; j--) {
//                 if (nums[i] > nums[j]) {
//                     lisLength[i] = max(lisLength[i], lisLength[j] + 1);
//                 }
//             }
//         }

//         for (int i = N - 1; i >= 0; i--) {
//             for (int j = i + 1; j < N; j++) {
//                 if (nums[i] > nums[j]) {
//                     ldsLength[i] = max(ldsLength[i], ldsLength[j] + 1);
//                 }
//             }
//         }

//         int minRemovals = INT_MAX;
//         for (int i = 0; i < N; i++) {
//             if (lisLength[i] > 1 && ldsLength[i] > 1) {
//                 minRemovals =
//                     min(minRemovals, N - lisLength[i] - ldsLength[i] + 1);
//             }
//         }

//         return minRemovals;
//     }
// };




class Solution {
public:
    vector<int> getLongestIncreasingSubsequenceLength(vector<int>& v) {
        vector<int> lisLen(v.size(), 1);
        vector<int> lis = {v[0]};

        for (int i = 1; i < v.size(); i++) {
            int index = lower_bound(lis.begin(), lis.end(), v[i]) - lis.begin();

            if (index == lis.size()) {
                lis.push_back(v[i]);
            } else {
                lis[index] = v[i];
            }

            lisLen[i] = lis.size();
        }

        return lisLen;
    }

    int minimumMountainRemovals(vector<int>& nums) {
        int N = nums.size();
        vector<int> lisLength = getLongestIncreasingSubsequenceLength(nums);

        reverse(nums.begin(), nums.end());
        vector<int> ldsLength = getLongestIncreasingSubsequenceLength(nums);
        reverse(ldsLength.begin(), ldsLength.end());

        int minRemovals = INT_MAX;
        for (int i = 0; i < N; i++) {
            if (lisLength[i] > 1 && ldsLength[i] > 1) {
                minRemovals =
                    min(minRemovals, N - lisLength[i] - ldsLength[i] + 1);
            }
        }

        return minRemovals;
    }
};