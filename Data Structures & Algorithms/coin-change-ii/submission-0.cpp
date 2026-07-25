class Solution {
public:
    int solve(int i,int curr,int amount, vector<int>& coins,vector<vector<int>>&dp){
        if(i>=coins.size()){
            return 0;
        }
        if(curr==amount){
            return 1;
        }
        if(dp[i][curr]!=-1){
            return dp[i][curr];
        }
        int inc=0;
        if(curr+coins[i]<=amount){
            inc=solve(i,curr+coins[i],amount,coins,dp);
        }
        int exc=solve(i+1,curr,amount,coins,dp);
        dp[i][curr]=inc+exc;
        return inc+exc;
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>>dp(coins.size(),vector<int>(amount+1,-1));
        return solve(0,0,amount,coins,dp);
    }
};
