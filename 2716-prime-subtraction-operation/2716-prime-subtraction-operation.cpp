// class Solution {
// public:
//     bool checkPrime(int x) {
//         for (int i = 2; i <= sqrt(x); i++) {
//             if (x % i == 0) {
//                 return 0;
//             }
//         }
//         return 1;
//     }
//     bool primeSubOperation(vector<int>& nums) {
//         for (int i = 0; i < nums.size(); i++) {
//             int bound ;
//             if (i == 0) {
//                 bound = nums[0];
//             } else {
//                 bound = nums[i] - nums[i - 1];
//             }
//             if (bound <= 0) {
//                 return 0;
//             }

//             int largestPrime = 0;
//             for (int j = bound - 1; j >= 2; j--) {
//                 if (checkPrime(j)) {
//                     largestPrime = j;
//                     break;
//                 }
//             }

//             nums[i] = nums[i] - largestPrime;
//         }
//         return 1;
//     }
// };

class Solution {
public:
    bool checkPrime(int x) {
        for (int i = 2; i <= sqrt(x); i++) {
            if (x % i == 0) {
                return 0;
            }
        }
        return 1;
    }
    bool primeSubOperation(vector<int>& nums) {
        int maxElement = *max_element(nums.begin(), nums.end());

        // Store the previousPrime array.
        vector<int> previousPrime(maxElement + 1, 0);
        for (int i = 2; i <= maxElement; i++) {
            if (checkPrime(i)) {
                previousPrime[i] = i;
            } else {
                previousPrime[i] = previousPrime[i - 1];
            }
        }

        for (int i = 0; i < nums.size(); i++) {
            int bound;
            if (i == 0) {
                bound = nums[0];
            } else {
                bound = nums[i] - nums[i - 1];
            }

            if (bound <= 0) {
                return 0;
            }

            int largestPrime = previousPrime[bound - 1];

            nums[i] = nums[i] - largestPrime;
        }
        return 1;
    }
};