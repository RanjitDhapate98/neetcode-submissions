class Solution {
public:
    bool solve(int i,vector<int>& nums,vector<bool>&dp){
        if(i>=nums.size()-1){
            return true;
        }
        if(nums[i]==0){
            return false;
        }
        if(dp[i]==true){
            return dp[i];
        }
        bool ans=false;
        for(int j=1;j<=nums[i];j++){
            ans=solve(i+j,nums,dp);
            if(ans==true){
                return true;
            }
        }
        dp[i]=ans;
        return ans;
    }
    bool canJump(vector<int>& nums) {
        vector<bool>dp(nums.size()+1,false);
        if(nums.size()==0){
            return true;
        }
       return solve(0,nums,dp); 
    }
};
