class Solution {
public:
    bool issafe(int a,int b,int i,int j,vector<vector<int>>& nums){
          return (i>=0 && j>=0 && i<nums.size() && j<nums[0].size() && nums[i][j]>nums[a][b]);
    }
    int solve(int i,int j,vector<vector<int>>& nums,vector<vector<int>>&dp){
        vector<int>row={1,0,-1,0};
        vector<int>col={0,1,0,-1};
        int ans=0;
        if(dp[i][j]!=INT_MIN){
            return dp[i][j];
        }
        for(int a=0;a<4;a++){
            int newi=i+row[a];
            int newj=j+col[a];
            if(issafe(i,j,newi,newj,nums)){
                ans=max(ans,1+solve(newi,newj,nums,dp));
            } 
        }
        dp[i][j]=ans;
        return ans;
    }
    int longestIncreasingPath(vector<vector<int>>& nums) {
       int ans=INT_MIN;
       vector<vector<int>>dp(nums.size(),vector<int>(nums[0].size(),INT_MIN));
       for(int i=0;i<nums.size();i++){
        for(int j=0;j<nums[0].size();j++){
            int temp=solve(i,j,nums,dp);
            ans=max(ans,temp);
        }
       }
       return ans+1;
    }
};
