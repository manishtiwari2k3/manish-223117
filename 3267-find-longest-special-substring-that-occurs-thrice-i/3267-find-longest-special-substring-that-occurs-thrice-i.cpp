// class Solution {
// public:
//     int maximumLength(string s) {
//         map<string, int> count;
//         for (int start = 0; start < s.length(); start++) {
//             string currString;
//             for (int end = start; end < s.length(); end++) {
//                 if (currString.empty() or currString.back() == s[end]) {
//                     currString.push_back(s[end]);
//                     count[currString]++;
//                 } else {
//                     break;
//                 }
//             }
//         }

//         int ans = 0;
//         for (auto i : count) {
//             string str = i.first;
//             if (i.second >= 3 && str.length() > ans) ans = str.length();
//         }
//         if (ans == 0) return -1;
//         return ans;
//     }
// };

class Solution {
public:
    int maximumLength(string s) {
        map<pair<char, int>, int> count;
        int substringLength = 0;
        for (int start = 0; start < s.length(); start++) {
            char character = s[start];
            substringLength = 0;
            for (int end = start; end < s.length(); end++) {
                if (character == s[end]) {
                    substringLength++;
                    count[{character, substringLength}]++;
                } else {
                    break;
                }
            }
        }

        int ans = 0;
        for (auto i : count) {
            int len = i.first.second;
            if (i.second >= 3 && len > ans) ans = len;
        }
        if (ans == 0) return -1;
        return ans;
    }
};