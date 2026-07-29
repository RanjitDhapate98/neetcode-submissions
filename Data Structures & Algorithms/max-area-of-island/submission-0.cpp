class Solution {
public:
    bool issafe(int i,int j,vector<vector<int>>& grid,vector<vector<bool>>&visited){
        return (i>=0 && j>=0 && i<grid.size() && j<grid[0].size() && grid[i][j]==1 && !visited[i][j]);
    }
    void solve(int i,int j,vector<vector<int>>& grid,vector<vector<bool>>&visited,int &ans){
        visited[i][j]=true;
        vector<int>row={1,0,-1,0};
        vector<int>col={0,1,0,-1};
        for(int k=0;k<4;k++){
            int newi=i+row[k];
            int newj=j+col[k];
            if(issafe(newi,newj,grid,visited)){
                ans+=1;
                solve(newi,newj,grid,visited,ans);
            }
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        vector<vector<bool>>visited(grid.size(),vector<bool>(grid[0].size(),false));
        int ans=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1 && !visited[i][j]){
                    int temp=1;
                    solve(i,j,grid,visited,temp);
                    ans=max(ans,temp);
                }
            }
        }
        return ans;
    }
};
