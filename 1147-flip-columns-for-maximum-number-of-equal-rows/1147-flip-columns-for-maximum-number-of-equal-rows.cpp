// class Solution {
// public:
//     int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
//         int numCols = matrix[0].size();
//         int maxIdenticalRows = 0;

//         for (auto& currentRow : matrix) {
//             vector<int> flippedRow(numCols);
//             int identicalRowCount = 0;

//             for (int col = 0; col < numCols; col++) {
//                 flippedRow[col] = 1 - currentRow[col];
//             }

//             for (auto& compareRow : matrix) {
//                 if (compareRow == currentRow || compareRow == flippedRow) {
//                     identicalRowCount++;
//                 }
//             }

//             maxIdenticalRows = max(maxIdenticalRows, identicalRowCount);
//         }

//         return maxIdenticalRows;
//     }
// };




class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string, int> patternFrequency;

        for (auto& currentRow : matrix) {
            string patternBuilder = "";

            for (int col = 0; col < currentRow.size(); col++) {
                if (currentRow[0] == currentRow[col]) {
                    patternBuilder += "T";
                } else {
                    patternBuilder += "F";
                }
            }

            patternFrequency[patternBuilder]++;
        }

        int maxFrequency = 0;
        for (auto& entry : patternFrequency) {
            maxFrequency = max(entry.second, maxFrequency);
        }

        return maxFrequency;
    }
};