class Solution {
public:
    void bfs(int source, int destination,vector<bool>&vis, vector<vector<int>>& adj){
        if(source==destination){
            vis[destination]=true;
        }
        queue<int>q;
        q.push(source);
        vis[source]=true;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto it : adj[node]){
                if(!vis[it]){
                    vis[it]=true;
                    q.push(it);
                }
            }
        }
    
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<bool>vis(n,false);
        vector<vector<int>> adj(n);
        for(auto e:edges){
            int u=e[0];
            int v=e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            
        }
        bfs(source,destination,vis,adj);
            
            return vis[destination];
       
    }
};