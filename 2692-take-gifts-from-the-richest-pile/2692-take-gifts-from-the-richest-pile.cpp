// class Solution {
// public:
//     long long pickGifts(vector<int>& gifts, int k) {
//         int n = gifts.size();

//         for (int i = 0; i < k; i++) {
//             int richestPileIndex = 0;
//             for (int currentPileIndex = 0; currentPileIndex < n;
//                  currentPileIndex++) {
//                 if (gifts[richestPileIndex] < gifts[currentPileIndex]) {
//                     richestPileIndex = currentPileIndex;
//                 }
//             }

//             gifts[richestPileIndex] = sqrt(gifts[richestPileIndex]);
//         }

//         long long int numberOfRemainingGifts =
//             accumulate(gifts.begin(), gifts.end(), 0LL);

//         return numberOfRemainingGifts;
//     }
// };

class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        int n = gifts.size();

        vector<int> sortedGifts = gifts;
        sort(sortedGifts.begin(), sortedGifts.end());

        for (int i = 0; i < k; i++) {
            int maxElement = sortedGifts[n - 1];
            sortedGifts.pop_back();

            auto spotOfSqrt = upper_bound(sortedGifts.begin(),
                                          sortedGifts.end(), sqrt(maxElement));

            sortedGifts.emplace(spotOfSqrt, sqrt(maxElement));
        }

        long long int numberOfRemainingGifts =
            accumulate(sortedGifts.begin(), sortedGifts.end(), 0LL);

        return numberOfRemainingGifts;
    }
};