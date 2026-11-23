class Solution {
public:
    void bfs(int s,vector<int>&vis,vector<vector<int>>& isConnected){
        int n=isConnected.size();
        queue<int>q;
        q.push(s);
        vis[s]=1;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(int it=0;it<n;it++){
                if(!vis[it] &&  isConnected[node][it]==1){
                    vis[it]=1;
                    q.push(it);
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {

        int n=isConnected.size();
        int count=0;
        vector<int>vis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                bfs(i,vis,isConnected);
                count++;
            }
        }
        return count;
    }
};