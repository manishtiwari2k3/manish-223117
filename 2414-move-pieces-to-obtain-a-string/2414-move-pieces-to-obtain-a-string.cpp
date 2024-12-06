// class Solution {
// public:
//     bool canChange(string start, string target) {
//         unordered_set<string> visitedStates;
//         queue<string> stateQueue;
//         stateQueue.push(start);

//         while (!stateQueue.empty()) {
//             string currentState = stateQueue.front();
//             stateQueue.pop();

//             if (currentState == target) return true;

//             for (int position = 1; position < currentState.size(); position++) {
//                 if (currentState[position] == 'L' &&
//                     currentState[position - 1] == '_') {
//                     swap(currentState[position], currentState[position - 1]);
//                     if (visitedStates.find(currentState) ==
//                         visitedStates.end()) {
//                         stateQueue.push(currentState);
//                         visitedStates.insert(currentState);
//                     }
//                     swap(currentState[position], currentState[position - 1]);
//                 }
//                 if (currentState[position - 1] == 'R' &&
//                     currentState[position] == '_') {
//                     swap(currentState[position], currentState[position - 1]);
//                     if (visitedStates.find(currentState) ==
//                         visitedStates.end()) {
//                         stateQueue.push(currentState);
//                         visitedStates.insert(currentState);
//                     }
//                     swap(currentState[position], currentState[position - 1]);
//                 }
//             }
//         }

//         return false;
//     }
// };

class Solution {
public:
    bool canChange(string start, string target) {
        queue<pair<char, int>> startQueue, targetQueue;

        for (int i = 0; i < start.size(); i++) {
            if (start[i] != '_') {
                startQueue.push({start[i], i});
            }
            if (target[i] != '_') {
                targetQueue.push({target[i], i});
            }
        }

        if (startQueue.size() != targetQueue.size()) return false;

        while (!startQueue.empty()) {
            auto [startChar, startIndex] = startQueue.front();
            startQueue.pop();
            auto [targetChar, targetIndex] = targetQueue.front();
            targetQueue.pop();

            if (startChar != targetChar ||
                (startChar == 'L' && startIndex < targetIndex) ||
                (startChar == 'R' && startIndex > targetIndex))
                return false;
        }

        return true;
    }
};