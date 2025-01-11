// class Solution {
// public:
//     bool canConstruct(string s, int k) {
//         if (s.length() < k) return false;
//         if (s.length() == k) return true;

//         vector<int> freq(26);
//         int oddCount = 0;

//         for (auto& chr : s) freq[chr - 'a']++;

//         for (int i = 0; i < 26; i++) {
//             if (freq[i] % 2 == 1) {
//                 oddCount++;
//             }
//         }

//         return (oddCount <= k);
//     }
// };


class Solution {
public:
    bool canConstruct(string s, int k) {
        // Handle edge cases
        if (s.length() < k) return false;
        if (s.length() == k) return true;

        // Initialize oddCount as an integer bitmask
        int oddCount = 0;

        // Update the bitmask for each character in the string
        for (char chr : s) {
            oddCount ^= 1 << (chr - 'a');
        }

        // Count the number of set bits in the bitmask
        int setBits = __builtin_popcount(oddCount);

        // Return if the number of odd frequencies is less than or equal to k
        return setBits <= k;
    }
};