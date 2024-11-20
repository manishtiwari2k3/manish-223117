// class Solution {
//     int minMinutes = INT_MAX;

// public:
//     int takeCharacters(string s, int k) {
//         if (k == 0) return 0;
//         vector<int> count(3, 0);
//         solve(s, k, 0, s.length() - 1, count, 0);
//         return minMinutes == INT_MAX ? -1 : minMinutes;
//     }

// public:
//     void solve(string& s, int k, int left, int right, vector<int> count,
//                int minutes) {
//         if (count[0] >= k && count[1] >= k && count[2] >= k) {
//             minMinutes = min(minMinutes, minutes);
//             return;
//         }
//         if (left > right) return;

//         vector<int> leftCount = count;
//         leftCount[s[left] - 'a']++;
//         solve(s, k, left + 1, right, leftCount, minutes + 1);

//         vector<int> rightCount = count;
//         rightCount[s[right] - 'a']++;
//         solve(s, k, left, right - 1, rightCount, minutes + 1);
//     }
// };


class Solution {
public:
    int takeCharacters(string s, int k) {
        vector<int> count(3, 0);
        int n = s.length();

        for (char c : s) {
            count[c - 'a']++;
        }

        for (int i = 0; i < 3; i++) {
            if (count[i] < k) return -1;
        }

        vector<int> window(3, 0);
        int left = 0, maxWindow = 0;

        for (int right = 0; right < n; right++) {
            window[s[right] - 'a']++;

            while (left <= right &&
                   (count[0] - window[0] < k || count[1] - window[1] < k ||
                    count[2] - window[2] < k)) {
                window[s[left] - 'a']--;
                left++;
            }

            maxWindow = max(maxWindow, right - left + 1);
        }

        return n - maxWindow;
    }
};