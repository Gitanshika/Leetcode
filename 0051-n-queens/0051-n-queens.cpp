class Solution {
public:
     vector<vector<string>>ans;
    bool issafe(int i, int col,vector<string>&board,int n){
        

        for(int row=0;row<i;row++){
            if(board[row][col]=='Q') return false;
            
        }

        int c=col-1;
        int r=i-1;
        while(r>=0 && c>=0){
        if(board[r][c]=='Q'){
            return  false;
        }
        r--;
        c--;
    }
        r=i-1;
        c=col+1;
        while(r>=0 &&c<n){
            if(board[r][c]=='Q') return false;
            r--;
            c++;
        }
        return true;
    }
    void solve(int row,vector<string>&board,int n){
        if(row==n){
            ans.push_back(board);
            return;
        }
        for(int col=0;col<n;col++){
            if(issafe(row,col,board,n)){
                board[row][col]='Q';
                solve(row+1,board,n);
                board[row][col]='.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string>board(n,string(n,'.'));
       solve(0,board,n);
        return ans;
    }
};