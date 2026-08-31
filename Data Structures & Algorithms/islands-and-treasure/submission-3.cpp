class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==0){
                    q.push({i,j});
                }
            }
        }
        vector<int>row={1,0,-1,0};
        vector<int>col={0,1,0,-1};
        while(!q.empty()){
            auto top=q.front();
            q.pop();
            int i=top.first;
            int j=top.second;
            for(int a=0;a<4;a++){
                int ni=i+row[a];
                int nj=j+col[a];
                if(ni>=0 && nj>=0 && ni<grid.size() && nj<grid[0].size() && grid[ni][nj]==2147483647){
                    
                        grid[ni][nj]=grid[i][j]+1;
                        q.push({ni,nj});
                    
                }
            }
            
        }
        
    }
};
