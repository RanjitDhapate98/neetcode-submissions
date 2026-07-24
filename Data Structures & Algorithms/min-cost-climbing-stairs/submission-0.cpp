class Solution {
public:
    int solve(int i,vector<int>&cost,vector<int>&dp){
        if(i>=cost.size()){
            return 0;
        }
        if(dp[i]!=0){
            return dp[i];
        }
        int one=cost[i]+solve(i+1,cost,dp);
        int two=cost[i]+solve(i+2,cost,dp);
        dp[i]= min(one,two);
        return dp[i];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int>dp(cost.size()+1,0);
        return min(solve(0,cost,dp),solve(1,cost,dp));
    }
};
