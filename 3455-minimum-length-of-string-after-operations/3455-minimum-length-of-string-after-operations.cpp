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
        vector<int> charFrequency(26, 0);
        int totalLength = 0;

        for (char currentChar : s) {
            charFrequency[currentChar - 'a']++;
        }

        for (int frequency : charFrequency) {
            if (frequency == 0) continue;  
            if (frequency % 2 == 0) {
                totalLength += 2; 
            } else {
                totalLength += 1;
            }
        }

        return totalLength;
    }
};