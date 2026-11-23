class Solution {
public:
    void dfs(int s,vector<int>&vis,vector<vector<int>>& isConnected){
        int n=isConnected.size();
        vis[s]=1;
            for(int it=0;it<n;it++){
                if(!vis[it] &&  isConnected[s][it]==1){
                   dfs(it,vis,isConnected);
                }
            }
        
    }
    int findCircleNum(vector<vector<int>>& isConnected) {

        int n=isConnected.size();
        int count=0;
        vector<int>vis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,vis,isConnected);
                count++;
            }
        }
        return count;
    }
};