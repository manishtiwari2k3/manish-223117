// class Solution {
// public:
//     bool canBeValid(string s, string locked) {
//         int length = s.size();
//         if (length % 2 == 1) {
//             return false;
//         }

//         stack<int> openBrackets, unlocked;

//         for (int i = 0; i < length; i++) {
//             if (locked[i] == '0') {
//                 unlocked.push(i);
//             } else if (s[i] == '(') {
//                 openBrackets.push(i);
//             } else if (s[i] == ')') {
//                 if (!openBrackets.empty()) {
//                     openBrackets.pop();
//                 } else if (!unlocked.empty()) {
//                     unlocked.pop();
//                 } else {
//                     return false;
//                 }
//             }
//         }

//         while (!openBrackets.empty() && !unlocked.empty() &&
//                openBrackets.top() < unlocked.top()) {
//             openBrackets.pop();
//             unlocked.pop();
//         }

//         if (!openBrackets.empty()) {
//             return false;
//         }

//         return true;
//     }
// };


class Solution {
public:
    bool canBeValid(string s, string locked) {
        int length = s.size();
        // If length of string is odd, return false.
        if (length % 2 == 1) {
            return false;
        }
        int openBrackets = 0, unlocked = 0;
        for (int i = 0; i < length; i++) {
            if (locked[i] == '0') {
                unlocked++;
            } else if (s[i] == '(') {
                openBrackets++;
            } else if (s[i] == ')') {
                if (openBrackets > 0) {
                    openBrackets--;
                } else if (unlocked > 0) {
                    unlocked--;
                } else {
                    return false;
                }
            }
        }
        int balance = 0;
        for (int i = length - 1; i >= 0; i--) {
            if (locked[i] == '0') {
                balance--;
                unlocked--;
            } else if (s[i] == '(') {
                balance++;
                openBrackets--;
            } else if (s[i] == ')') {
                balance--;
            }
            if (balance > 0) {
                return false;
            }
            if (unlocked == 0 and openBrackets == 0) {
                break;
            }
        }

        if (openBrackets > 0) {
            return false;
        }

        return true;
    }
};