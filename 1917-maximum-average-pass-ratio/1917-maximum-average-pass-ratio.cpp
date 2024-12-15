// class Solution {
// public:
//     double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
//         vector<double> passRatios;

//         for (int classIndex = 0; classIndex < classes.size(); classIndex++) {
//             double initialRatio =
//                 classes[classIndex][0] / (double)classes[classIndex][1];
//             passRatios.push_back(initialRatio);
//         }

//         while (extraStudents--) {
//             vector<double> updatedRatios;

//             for (int classIndex = 0; classIndex < classes.size();
//                  classIndex++) {
//                 double newRatio = (classes[classIndex][0] + 1) /
//                                   (double)(classes[classIndex][1] + 1);
//                 updatedRatios.push_back(newRatio);
//             }

//             int bestClassIndex = 0;
//             double maximumGain = 0;

//             for (int classIndex = 0; classIndex < updatedRatios.size();
//                  classIndex++) {
//                 double gain =
//                     updatedRatios[classIndex] - passRatios[classIndex];
//                 if (gain > maximumGain) {
//                     bestClassIndex = classIndex;
//                     maximumGain = gain;
//                 }
//             }

//             passRatios[bestClassIndex] = updatedRatios[bestClassIndex];
//             classes[bestClassIndex][0]++;
//             classes[bestClassIndex][1]++;
//         }

//         double totalPassRatio = 0;
//         for (double passRatio : passRatios) {
//             totalPassRatio += passRatio;
//         }

//         return totalPassRatio / classes.size();
//     }
// };


class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        auto calculateGain = [](int passes, int totalStudents) {
            return (double)(passes + 1) / (totalStudents + 1) -
                   (double)passes / totalStudents;
        };
        priority_queue<pair<double, pair<int, int>>> maxHeap;
        for (const auto& singleClass : classes) {
            maxHeap.push({calculateGain(singleClass[0], singleClass[1]),
                          {singleClass[0], singleClass[1]}});
        }

        while (extraStudents--) {
            auto [currentGain, classInfo] = maxHeap.top();
            maxHeap.pop();
            int passes = classInfo.first;
            int totalStudents = classInfo.second;
            maxHeap.push({calculateGain(passes + 1, totalStudents + 1),
                          {passes + 1, totalStudents + 1}});
        }

        double totalPassRatio = 0;
        while (!maxHeap.empty()) {
            auto [_, classInfo] = maxHeap.top();
            maxHeap.pop();
            totalPassRatio += (double)classInfo.first / classInfo.second;
        }

        return totalPassRatio / classes.size();
    }
};