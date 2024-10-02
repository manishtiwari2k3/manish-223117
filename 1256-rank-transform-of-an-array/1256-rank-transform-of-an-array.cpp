class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        map<int, int> mpp;
        vector<int> sortedArr(arr);
        sort(sortedArr.begin(), sortedArr.end());
        int cnt = 1;
        for (int i = 0; i < sortedArr.size(); i++) {
            if (i > 0 && sortedArr[i] > sortedArr[i - 1]) {
                cnt++;
            }
            mpp[sortedArr[i]] = cnt;
        }
        for (int i = 0; i < arr.size(); i++) {
            arr[i] = mpp[arr[i]];
        }
        return arr;
    }
};