class Solution {
public:
    int solve(int i,int j,vector<vector<bool>>&visited,vector<vector<int>>& grid){
        if((i<0 || j<0) ||(i>=grid.size() || j>=grid[0].size()) || grid[i][j]==0 ){
            return 1;
        }
        if(visited[i][j]){
            return 0;
        }
        visited[i][j]=true;
        
        vector<int>row={1,0,-1,0};
        vector<int>col={0,1,0,-1};
        int ans=0;
        for(int a=0;a<4;a++){
             int b=row[a]+i;
             int c=col[a]+j;
             
                ans+=solve(b,c,visited,grid);
              
             
        }
        return ans;
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        vector<vector<bool>>visited(grid.size(),vector<bool>(grid[0].size(),false));
        int ans=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1 && visited[i][j]==false){
                    ans+=solve(i,j,visited,grid);
                }
            }
        }
        return ans;
    }
};