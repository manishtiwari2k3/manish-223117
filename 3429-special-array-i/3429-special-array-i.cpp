class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        for (int index = 0; index < nums.size() - 1; index++) {
            if (nums[index] % 2 == nums[index + 1] % 2) {
                return false;
            }
        }

        // Return true if no pair of adjacent numbers with the same parity are
        // found
        return true;
    }
};