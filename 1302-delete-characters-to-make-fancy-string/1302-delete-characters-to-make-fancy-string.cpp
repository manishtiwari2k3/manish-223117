// class Solution {
// public:
//     string makeFancyString(string s) {
//         char prev = s[0];
//         int frequency = 1;
//         string ans = "";
//         ans.push_back(s[0]);

//         for (int i = 1; i < s.size(); i++) {
//             if (s[i] == prev) {
//                 frequency++;
//             } else {
//                 prev = s[i];
//                 frequency = 1;
//             }

//             if (frequency < 3) ans.push_back(s[i]);
//         }

//         return ans;
//     }
// };




class Solution {
public:
    string makeFancyString(string s) {
        if (s.length() < 3) {
            return s;
        }
        int j = 2;
        for (int i = 2; i < s.size(); ++i) {
            if (s[i] != s[j - 1] || s[i] != s[j - 2]) {
                s[j++] = s[i];
            }
        }

        s.resize(j);
        return s;
    }
};