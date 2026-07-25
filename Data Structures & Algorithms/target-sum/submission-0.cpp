class Solution {
public:
    int solve(int i,int curr,vector<int>& nums, int target,vector<vector<int>>&dp,int s){
        if(i>=nums.size()){
            if(curr==target){
                return 1;
            }else
            return 0;
        }
       if(dp[i][curr+s]!=INT_MAX){
        return dp[i][curr+s];
       }
        int sub=solve(i+1,curr-nums[i],nums,target,dp,s);
        int sum=solve(i+1,curr+nums[i],nums,target,dp,s);
        dp[i][curr+s]= sub+sum;
        return dp[i][curr+s];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        
         vector<vector<int>>dp(nums.size(),vector<int>(2*sum+1,INT_MAX));
        return solve(0,0,nums,target,dp,sum);
    }
};
