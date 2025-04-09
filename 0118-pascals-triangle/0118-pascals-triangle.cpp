class Solution {
public:
    vector <int> generateRow(int row){
        long long ans = 1;
        vector<int>ansi;
        ansi.push_back(1);
        for(int i=1;i<row;i++){
            ans = ans*(row-i);
            ans = ans/i;
            ansi.push_back(ans);
        }
        return ansi;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        for(int i=1;i<=numRows;i++){
            ans.push_back(generateRow(i));
        }
        return ans;
    }
};