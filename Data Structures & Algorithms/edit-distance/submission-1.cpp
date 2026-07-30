class Solution {
public:
    int solve(int i,int j,string word1, string word2,vector<vector<int>>&dp){
        if(i>=word1.size() && j>=word2.size()){
            return 0;
        }
        if(i>=word1.size() && j<word2.size()){
            return word2.size()-j;
        }
        if(j>=word2.size() && i<word1.size()){
            return word1.size()-i;
        }
        if(dp[i][j]!=INT_MAX){
            return dp[i][j];
        }
        int inc=0;
        if(word1[i]==word2[j]){
            inc=solve(i+1,j+1,word1,word2,dp);
        }else{
            int ins=1+solve(i,j+1,word1,word2,dp);
            int del=1+solve(i+1,j,word1,word2,dp);
            int repl=1+solve(i+1,j+1,word1,word2,dp);
            inc=min(ins,min(del,repl));
        }
        dp[i][j]=inc;
        return inc;
    }
    int minDistance(string word1, string word2) {
        vector<vector<int>>dp(word1.size(),vector<int>(word2.size(),INT_MAX));
        return solve(0,0,word1,word2,dp);
    }
};
