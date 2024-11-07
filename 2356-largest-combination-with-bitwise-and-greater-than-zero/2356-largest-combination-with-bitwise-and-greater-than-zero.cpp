// class Solution {
// public:
//     int largestCombination(vector<int>& candidates){
//         vector<int> bitCount(24, 0);
//         for (int i = 0; i < 24; i++) {
//             for (int num : candidates) {
//                 if ((num & (1 << i)) != 0) {
//                     bitCount[i]++;
//                 }
//             }
//         }
//         return *max_element(bitCount.begin(), bitCount.end());
//     }
// };



class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int maxCount = 0;
        for (int i = 0; i < 24; i++) {
            int count = 0 ;
            for (int num : candidates) {
                if ((num & (1 << i)) != 0) {
                    count++;
                }
            }
            maxCount = max(maxCount, count); 
        }
        return maxCount;
    }
};