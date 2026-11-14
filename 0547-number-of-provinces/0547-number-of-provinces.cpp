class Solution {
public:
    void bfs(int start, vector<vector<int>>& adj, vector<int>& visited) {
        int n=adj.size();
        queue<int> q;
        q.push(start);
        visited[start] = 1;

        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(int j=0;j<n;j++){
                if(adj[node][j]==1 && visited[j]!=1){
                    visited[j]=1;
                    q.push(j);
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int> visited(n, 0);
        int count = 0;

        for(int i = 0; i < n; i++) {
            if(visited[i] == 0) {
                bfs(i, isConnected, visited);
                count++;
            }
        }

        return count;
    }
};
    