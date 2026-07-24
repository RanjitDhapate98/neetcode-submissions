class Solution {
public:
    int solve(int prev,int i,vector<int>& nums,vector<vector<int>>&dp){
        if(i>=nums.size()){
            return 0;
        }
        if(dp[i][prev+1]!=-1){
            return dp[i][prev+1];
        }
        int inc=0;
        if(prev==-1 || nums[i]>nums[prev]){
            inc=1+solve(i,i+1,nums,dp);
        }
        int exc=solve(prev,i+1,nums,dp);
        dp[i][prev+1]=max(inc,exc);
        return max(inc,exc);
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>>dp(nums.size()+1,vector<int>(nums.size()+1,-1));
        return solve(-1,0,nums,dp);
    }
};
