class Solution {
public:
     bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum&1) return 0;
        int K=sum/2;
        bitset<10001> dp;
        dp[K]=1;
        for (int x: nums) {
            dp|= dp>>x;
            if (dp[0]) return 1;//early stop
        }
        return dp[0];
    }
};