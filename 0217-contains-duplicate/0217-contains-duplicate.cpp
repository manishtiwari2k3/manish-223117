#include<bits/stdc++.h>
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();
       unordered_map <int,int> mpp;
        for(auto i : nums){
            if(mpp.count(i)){
                return true;
            }
            mpp[i]++;
        }
        return false;
    }
};