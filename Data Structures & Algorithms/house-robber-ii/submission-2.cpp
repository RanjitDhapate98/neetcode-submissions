class Solution {
public:
    int solve(int i,vector<int>& nums,vector<int>&dp,int l){
        if(i>l){
            return 0;
        }
        
        if(dp[i]!=INT_MIN){
            return dp[i];
        }
        int inc=nums[i]+solve(i+2,nums,dp,l);
        int exc=solve(i+1,nums,dp,l);
        dp[i]= max(inc,exc);
        return dp[i];
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1){
            return nums[0];
        }
        vector<int>dp1(nums.size()+1,INT_MIN);
        vector<int>dp2(nums.size()+1,INT_MIN);
        int n=nums.size()-1;
        return max(solve(0,nums,dp1,n-1),solve(1,nums,dp2,n));
    }
};
