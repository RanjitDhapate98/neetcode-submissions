class Solution {
public:
    bool issafe(int i,int j,vector<vector<bool>>&visited,vector<vector<char>>&board){
        return (i>=0 && j>=0 && i<board.size() && j<board[0].size() && board[i][j]=='O'&& !visited[i][j]);
    }
   void dfs(int i,int j,vector<vector<bool>>&visited,vector<vector<char>>&board){
    visited[i][j]=true;
    vector<int>row={1,0,-1,0};
    vector<int>col={0,1,0,-1};
    for(int k=0;k<4;k++){
        int newi=i+row[k];
        int newj=j+col[k];
        if(issafe(newi,newj,visited,board)){
            dfs(newi,newj,visited,board);
        }
    }
   }
    void solve(vector<vector<char>>& board) {
       
        vector<vector<bool>>visited(board.size(),vector<bool>(board[0].size(),false));
        int m=board.size()-1;
        int n=board[0].size()-1;
        for(int i=0;i<=n;i++){
            if(!visited[0][i] && board[0][i]=='O'){
                dfs(0,i,visited,board);
            }
            if(!visited[m][i] && board[m][i]=='O'){
                dfs(m,i,visited,board);
            }
        }
        for(int i=0;i<=m;i++){
            if(!visited[i][0] && board[i][0]=='O'){
                dfs(i,0,visited,board);
            }
            if(!visited[i][n] && board[i][n]=='O'){
                dfs(i,n,visited,board);
            }
        }
        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
                if(!visited[i][j]){
                    board[i][j]='X';
                }
            }
        }
    }
};
