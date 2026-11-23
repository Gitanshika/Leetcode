class Solution {
public:
    int bfs(int i ,int j,vector<vector<int>>& grid,vector<vector<bool>>& vis){
        int area=0;
        int m=grid.size();
        int n=grid[0].size();
        queue<pair<int,int>>q;
        q.push({i,j});
        vis[i][j]=true;
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            area+=1;
            int r=it.first;
            int c=it.second;
            if(r-1>=0  && grid[r-1][c]==1 && vis[r-1][c]==false){
                vis[r-1][c]=true;
                q.push({r-1,c});
            }
            if(r+1 < m && grid[r+1][c] == 1 && !vis[r+1][c]) {
            vis[r+1][c] = true;
            q.push({r+1,c});
            
        }
       

        
        if(c-1 >= 0 && grid[r][c-1] == 1 && !vis[r][c-1]) {
            vis[r][c-1] = true;
            q.push({r,c-1});
        }

        // RIGHT
        if(c+1 < n && grid[r][c+1] == 1 && !vis[r][c+1]) {
            vis[r][c+1] = true;
            q.push({r,c+1});
        }

        }
        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxi=0;
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<bool>>vis(m,vector<bool>(n,false));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 && vis[i][j]==false){
                    vis[i][j]=true;
                    int area=bfs(i,j,grid,vis);
                    maxi=max(maxi,area);
                }
            }
        }
    return maxi;
    }
};