// class Solution {
// public:
//     int minGroups(vector<vector<int>>& intervals) {
//         vector<pair<int, int>> intervalsWithEnd;
//         for (vector<int> interval : intervals) {
//             intervalsWithEnd.push_back({interval[0], 1});
//             intervalsWithEnd.push_back({interval[1] + 1, -1});
//         }

//         sort(intervalsWithEnd.begin(), intervalsWithEnd.end());

//         int concurrentIntervals = 0;
//         int maxConcurrentIntervals = 0;
//         for (auto i : intervalsWithEnd) {
//             concurrentIntervals += i.second;
//             maxConcurrentIntervals =
//                 max(maxConcurrentIntervals, concurrentIntervals);
//         }

//         return maxConcurrentIntervals;
//     }
// };




class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        map<int, int> pointToCount;
        for (vector<int> interval : intervals) {
            pointToCount[interval[0]]++;
            pointToCount[interval[1] + 1]--;
        }

        int concurrentIntervals = 0;
        int maxConcurrentIntervals = 0;
        for (pair<int, int> p : pointToCount) {
            concurrentIntervals += p.second;

            maxConcurrentIntervals =
                max(maxConcurrentIntervals, concurrentIntervals);
        }

        return maxConcurrentIntervals;
    }
};