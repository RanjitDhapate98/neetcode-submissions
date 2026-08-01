class Solution {
public:
     bool issafe(int i,int j,int newi,int newj,vector<vector<bool>>&ocean,vector<vector<int>>& heights){
        int row=ocean.size();
        int col=ocean[0].size();
        return(newi>=0 && newj>=0 && newi<row && newj<col && ocean[newi][newj]!=1&& heights[newi][newj]>=heights[i][j]);
     }
     void dfs(int i,int j,vector<vector<bool>>&ocean,vector<vector<int>>& heights){
        ocean[i][j]=1;
        int dx[]={0,1,0,-1};
        int dy[]={1,0,-1,0};
        for(int a=0;a<4;a++){
            int newi=i+dx[a];
            int newj=j+dy[a];
            if(issafe(i,j,newi,newj,ocean,heights)){
                dfs(newi,newj,ocean,heights);
            }
        }
     }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int row=heights.size();
        int col=heights[0].size();
        vector<vector<bool>>pacific(row,vector<bool>(col,0));
        vector<vector<bool>>atlantic(row,vector<bool>(col,0));
        for(int i=0;i<col;i++){
           dfs(0,i,pacific,heights);
           dfs(row-1,i,atlantic,heights);
        }
        for(int i=0;i<row;i++){
            dfs(i,0,pacific,heights);
           dfs(i,col-1,atlantic,heights);
        }
        vector<vector<int>>ans;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(pacific[i][j]==1 && atlantic[i][j]==1){
                    vector<int>temp;
                    temp.push_back(i);
                    temp.push_back(j);
                    ans.push_back(temp);
                }
            }
        }
        return ans;
    }
};