// class Solution {
// public:
//     vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
//         int n = nums.size();

//         vector<int> prefixXOR(n);
//         prefixXOR[0] = nums[0];

//         for (int i = 1; i < n; i++) {
//             prefixXOR[i] = prefixXOR[i - 1] ^ nums[i];
//         }

//         vector<int> ans(n);
//         int mask = (1 << maximumBit) - 1;

//         for (int i = 0; i < n; i++) {
//             int currentXOR = prefixXOR[n - 1 - i];
//             ans[i] = currentXOR ^ mask;
//         }

//         return ans;
//     }
// };



class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int xorProduct = 0;
        for (int i = 0; i < nums.size(); i++) {
            xorProduct = xorProduct ^ nums[i];
        }
        vector<int> ans(nums.size());

        int mask = (1 << maximumBit) - 1;

        for (int i = 0; i < nums.size(); i++) {
            ans[i] = xorProduct ^ mask;
            xorProduct = xorProduct ^ nums[nums.size() - 1 - i];
        }

        return ans;
    }
};