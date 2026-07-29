class Solution {
public:
    bool issafe(int i,int j,vector<vector<bool>>&visited,vector<vector<char>>& grid){
        return (i>=0 && j>=0 && i<grid.size() && j<grid[0].size() && grid[i][j]=='1' && !visited[i][j]);
    }
    void solve(int i,int j,vector<vector<char>>& grid,vector<vector<bool>>&visited){
        visited[i][j]=true;
        vector<int>row={1,0,-1,0};
        vector<int>col={0,1,0,-1};
        for(int k=0;k<4;k++){
            int newi=row[k]+i;
            int newj=col[k]+j;
            if(issafe(newi,newj,visited,grid)){
                solve(newi,newj,grid,visited);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
       int ans=0;
       vector<vector<bool>>visited(grid.size(),vector<bool>(grid[0].size(),false));
       for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid[0].size();j++){
            if(grid[i][j]=='1' && !visited[i][j]){
                ans++;
                solve(i,j,grid,visited);
            }
        }
       }
       return ans;
    }
};
