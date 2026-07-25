class Solution {
public:
    bool solve(int i,int curr,int target,vector<int>& nums,vector<vector<int>>&dp){
        if(curr==target){
            return true;
        }
        if(i>=nums.size()){
            return false;
        }
        if(dp[i][curr]!=-1){
            return dp[i][curr];
        }
        bool inc=false;
        if(nums[i]+curr<=target){
            inc=solve(i+1,curr+nums[i],target,nums,dp);
        }
        bool exc=solve(i+1,curr,target,nums,dp);
        dp[i][curr]=inc||exc;
        return inc||exc;
    }
    bool canPartition(vector<int>& nums) {
        int total=accumulate(nums.begin(),nums.end(),0);
        if(total%2!=0){
            return false;
        }
        int target=total/2;
        vector<vector<int>>dp(nums.size(),vector<int>(target+1,-1));
        bool ans=solve(0,0,target,nums,dp);
        return ans;
    }
};
