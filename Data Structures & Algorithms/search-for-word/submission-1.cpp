class Solution {
public:
    bool issafe(int i,int j,vector<vector<char>>& board, string word,int a,vector<vector<bool>>&visited){
        return (i>=0 && j>=0 && i<board.size() && j<board[0].size() && board[i][j]==word[a] && !visited[i][j]);
    }
    bool solve(int i,int j,vector<vector<char>>& board, string word,int a,vector<vector<bool>>&visited){
        if(a==word.size()-1){
            return true;
        }
        visited[i][j]=true;
        vector<int>row={1,0,-1,0};
        vector<int>col={0,1,0,-1};
        for(int k=0;k<4;k++){
            int newi=i+row[k];
            int newj=j+col[k];
            if(issafe(newi,newj,board,word,a+1,visited)){
                bool ans=solve(newi,newj,board,word,a+1,visited);
                if(ans==true){
                    return true;
                }
            }
        }
          visited[i][j]=false;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        vector<pair<int,int>>vp;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]==word[0]){
                    vp.push_back({i,j});
                }
            }
        }
        for(auto i:vp){
            int a=i.first;
            int b=i.second;
            vector<vector<bool>>visited(board.size(),vector<bool>(board[0].size(),false));
            bool ans=solve(a,b,board,word,0,visited);
            if(ans==true){
                return true;
            }
        }
        return false;
    }
};
