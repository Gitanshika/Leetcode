class Solution {
public:
    void bfs(int s,vector<int>&vis,vector<vector<int>>& rooms){
        int n=rooms.size();
        queue<int>q;
        q.push(s);
        vis[s]=1;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto it:rooms[node]){
                if(!vis[it]){
                    vis[it]=1;
                    bfs(it,vis,rooms);
                }
            }

        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<int>vis(n,0);
        bfs(0,vis,rooms);

        for(int i=0;i<n;i++){
            if(vis[i]==0){
                return false;
            }
        }
        return true;
    }
};