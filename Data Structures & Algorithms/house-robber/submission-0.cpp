class Solution {
public:
    int solve(int i,vector<int>& nums,vector<int>&dp){
        if(i>=nums.size()){
            return 0;
        }
        if(dp[i]!=INT_MIN){
            return dp[i];
        }
        int inc=nums[i]+solve(i+2,nums,dp);
        int exc=solve(i+1,nums,dp);
        dp[i]= max(inc,exc);
        return dp[i];
    }
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size()+1,INT_MIN);
        return solve(0,nums,dp);
    }
};
