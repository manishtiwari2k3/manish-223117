// class Solution {
// public:
//     int minimumLength(string s) {
//         unordered_map<char, int> charFrequencyMap;
//         for (char currentChar : s) {
//             charFrequencyMap[currentChar]++;
//         }

//         int deleteCount = 0;
//         for (auto& pair : charFrequencyMap) {
//             int frequency = pair.second;
//             if (frequency % 2 == 1) {
//                 deleteCount += frequency - 1;
//             } else {
//                 deleteCount += frequency - 2;
//             }
//         }

//         return s.length() - deleteCount;
//     }
// };
class Solution {
public:
    int minimumLength(string s) {
        // Step 1: Initialize a frequency array to count occurrences of each
        // character
        vector<int> charFrequency(26, 0);
        int totalLength = 0;

        // Step 2: Count the frequency of each character in the string
        for (char currentChar : s) {
            charFrequency[currentChar - 'a']++;
        }

        // Step 3: Calculate the total length after deletions count
        for (int frequency : charFrequency) {
            if (frequency == 0) continue;  // Skip characters that don't appear
            if (frequency % 2 == 0) {
                totalLength += 2;  // If frequency is even, add 2
            } else {
                totalLength += 1;
            }
        }

        return totalLength;
    }
};