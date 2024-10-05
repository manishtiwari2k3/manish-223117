
// class Solution {
// public:
//     bool flag = false;

//     bool checkInclusion(string s1, string s2) {
//         permute(s1, s2, 0);
//         return flag;
//     }

//     string swap(string s, int i0, int i1) {
//         if (i0 == i1)
//             return s;
//         char temp = s[i0];
//         s[i0] = s[i1];
//         s[i1] = temp;
//         return s;
//     }

//     void permute(string s1, string s2, int l) {
//         if (l == s1.length()) {
//             if (s2.find(s1) != string::npos)  
//                 flag = true;
//         } else {
//             for (int i = l; i < s1.length(); i++) {
//                 s1 = swap(s1, l, i);
//                 permute(s1, s2, l + 1);
//                 s1 = swap(s1, l, i);  
//             }
//         }
//     }
// };


class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length())
            return false;
        vector<int> s1arr(26, 0);
        vector<int> s2arr(26, 0);

        for (int i = 0; i < s1.length(); i++) {
            s1arr[s1[i] - 'a']++;
            s2arr[s2[i] - 'a']++;
        }
        for (int i = 0; i < s2.length() - s1.length(); i++) {
            if (matches(s1arr, s2arr))
                return true;
            s2arr[s2[i + s1.length()] - 'a']++;
            s2arr[s2[i] - 'a']--;
        }

        return matches(s1arr, s2arr); 
    }

    bool matches(vector<int>& s1arr, vector<int>& s2arr) {
        for (int i = 0; i < 26; i++) {
            if (s1arr[i] != s2arr[i])
                return false;
        }
        return true;
    }
};
