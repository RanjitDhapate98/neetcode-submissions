class Solution {
public:
     int solve(int i,vector<int>& nums,vector<int>&dp){
        if(i>=nums.size()-1){
            return 0;
        }
        if(nums[i]==0){
            return 10000000;
        }
        if(dp[i]!=INT_MAX){
            return dp[i];
        }
        int inc=INT_MAX;
        for(int j=1;j<=nums[i];j++){
            inc=min(inc ,1+solve(i+j,nums,dp));
        }
        dp[i]=inc;
        return inc;
     }
    int jump(vector<int>& nums) {
        int ans=0;
        vector<int>dp(nums.size()+1,INT_MAX);
        return solve(0,nums,dp);
    }
};
