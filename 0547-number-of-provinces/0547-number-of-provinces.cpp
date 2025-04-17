class Solution {
public:
    void dfs(vector<vector<int>>&isConnected,int node,vector<int>&vis){
        vis[node] = 1;
        // for(auto it: adjLs[node]){
        //     if(!vis[it]){
        //         dfs(adjLs,it,vis);
        //     }
        // }
        for(int i=1;i<isConnected.size();i++){
            if(isConnected[node][i]==1 && !vis[i]){
                dfs(isConnected,i,vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        // converting adacency matrix to adjacency list
        // vector<vector<int>>adjLs(n);
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         if(isConnected[i][j]==1 && i!=j){
        //             adjLs[i].push_back(j);
        //             adjLs[j].push_back(i);
        //         }
        //     }
        // }

        vector<int>vis(n,0);
        int count = 0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                count++;
                dfs(isConnected,i,vis);
            }
        }
        return count;
    }
};