// class Solution {
// public:
//     vector<int> minOperations(string boxes) {
//         vector<int> answer(boxes.length());
//         for (int currentBox = 0; currentBox < boxes.length(); currentBox++) {
//             if (boxes[currentBox] == '1') {
//                 for (int newPosition = 0; newPosition < boxes.length();
//                      newPosition++) {
//                     answer[newPosition] += abs(newPosition - currentBox);
//                 }
//             }
//         }
//         return answer;
//     }
// };

class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> answer(n, 0);

        int ballsToLeft = 0, movesToLeft = 0;
        int ballsToRight = 0, movesToRight = 0;

        // Single pass: calculate moves from both left and right
        for (int i = 0; i < n; i++) {
            // Left pass
            answer[i] += movesToLeft;
            ballsToLeft += boxes[i] - '0';
            movesToLeft += ballsToLeft;

            // Right pass
            int j = n - 1 - i;
            answer[j] += movesToRight;
            ballsToRight += boxes[j] - '0';
            movesToRight += ballsToRight;
        }

        return answer;
    }
};