class Solution {
public:
    bool issafe(int i,int j,vector<vector<int>>& grid){
        return (i>=0 && j>=0 && i<grid.size() && j<grid[0].size() && grid[i][j]==1);
    }
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        int f=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    f++;
                }
                if(grid[i][j]==2){
                  q.push({i,j});
                }
            }
        }
        if(f==0){
            return 0;
        }
        int ans=0;
        while(!q.empty()){
            int n=q.size();
            ans++;
            for(int k=0;k<n;k++){
            auto top=q.front();
            q.pop();
            int i=top.first;
            int j=top.second;
            vector<int>row={1,0,-1,0};
            vector<int>col={0,1,0,-1};
            for(int a=0;a<4;a++){
                int newi=row[a]+i;
                int newj=col[a]+j;
                if(issafe(newi,newj,grid)){
                    grid[newi][newj]=2;
                    q.push({newi,newj});
                }
            }}
        
        }
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
    return ans-1;
    }
};
