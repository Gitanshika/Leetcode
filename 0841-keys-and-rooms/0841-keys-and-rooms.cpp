class Solution {
public:
    void bfs(int i, vector<vector<int>>& rooms, vector<int>& visited) {
        queue<int> q;
        q.push(i);
        visited[i] = 1;

        while(!q.empty()) {
            int node = q.front();
            q.pop();

            for(int j = 0; j < rooms[node].size(); j++) {
                int key = rooms[node][j];

                if(visited[key] == 0) {
                    visited[key] = 1;
                    q.push(key);
                }
            }
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();

        vector<int> visited(n, 0);
        visited[0]=1;
        bfs(0, rooms, visited);

        for(int i = 0; i < n; i++) {
            if(visited[i] == 0) {
                return false;
            }
        }

        return true;
    }
};