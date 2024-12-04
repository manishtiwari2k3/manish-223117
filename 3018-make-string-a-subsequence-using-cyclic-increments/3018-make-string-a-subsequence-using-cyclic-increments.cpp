// class Solution {
// public:
//     bool canMakeSubsequence(string str1, string str2) {
//         int lengthStr1 = str1.length();

//         for (int mask = 0; mask < (1 << lengthStr1); mask++) {
//             string temp = str1;

//             for (int str1Index = 0; str1Index < lengthStr1; str1Index++) {
//                 if (mask & (1 << str1Index)) {
//                     temp[str1Index] = getNextChar(temp[str1Index]);
//                 }
//             }

//             if (isSubsequence(temp, str2)) {
//                 return true;
//             }
//         }

//         return false;
//     }
// public:
//     char getNextChar(char str1Char) {
//         return str1Char == 'z' ? 'a' : str1Char + 1;
//     }

//     bool isSubsequence(string& str1, string& str2) {
//         int str1Index = 0, str2Index = 0;
//         int lengthStr1 = str1.size(), lengthStr2 = str2.size();

//         while (str1Index < lengthStr1 && str2Index < lengthStr2) {
//             if (str1[str1Index] == str2[str2Index]) {
//                 str2Index++;
//             }
//             str1Index++;
//         }
//         return str2Index == lengthStr2;
//     }
// };


class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int str2Index = 0;
        int lengthStr1 = str1.size(), lengthStr2 = str2.size();

        for (int str1Index = 0;
             str1Index < lengthStr1 && str2Index < lengthStr2; ++str1Index) {
            if (str1[str1Index] == str2[str2Index] ||
                (str1[str1Index] + 1 == str2[str2Index]) ||
                (str1[str1Index] - 25 == str2[str2Index])) {
                str2Index++;
            }
        }
        return str2Index == lengthStr2;
    }
};