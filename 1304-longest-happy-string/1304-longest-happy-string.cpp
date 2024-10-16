// class Solution {
// public:
//     string longestDiverseString(int a, int b, int c) {
//         priority_queue<pair<int, char>> pq;
//         if (a > 0) {
//             pq.push({a, 'a'});
//         }

//         if (b > 0) {
//             pq.push({b, 'b'});
//         }

//         if (c > 0) {
//             pq.push({c, 'c'});
//         }

//         string ans = "";
//         while (!pq.empty()) {
//             pair<int, char> p = pq.top();
//             pq.pop();
//             int count = p.first;
//             char character = p.second;
//             if (ans.length() >= 2 and ans[ans.length() - 1] == p.second and
//                 ans[ans.length() - 2] == p.second) {
//                 if (pq.empty()) break;

//                 pair<int, char> temp = pq.top();
//                 pq.pop();
//                 ans += temp.second;
//                 if (temp.first - 1 > 0) {
//                     pq.push({temp.first - 1, temp.second});
//                 }
//             } else {
//                 count--;
//                 ans = ans + character;
//             }

//             if (count > 0) {
//                 pq.push({count, character});
//             }
//         }
//         return ans;
//     }
// };





class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        int curra = 0, currb = 0, currc = 0;
        int totalIterations = a + b + c;
        string ans = "";

        for (int i = 0; i < totalIterations; i++) {
            if ((a >= b and a >= c and curra != 2) or
                (a > 0 and (currb == 2 or currc == 2))) {
                ans += 'a';
                a--;
                curra++;
                currb = 0;
                currc = 0;
            } else if ((b >= a and b >= c and currb != 2) or
                       (b > 0 and (currc == 2 or curra == 2))) {
                ans += 'b';
                b--;
                currb++;
                curra = 0;
                currc = 0;
            } else if ((c >= a and c >= b and currc != 2) or
                       (c > 0 and (curra == 2 or currb == 2))) {
                ans += 'c';
                c--;
                currc++;
                curra = 0;
                currb = 0;
            }
        }
        return ans;
    }
};