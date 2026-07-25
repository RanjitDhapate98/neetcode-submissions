class Solution {
public:
    int solve(int i,int j,string t1, string t2,vector<vector<int>>&dp){
        if(i>=t1.size() || j>=t2.size()){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int inc=0;
        if(t1[i]==t2[j]){
            inc=1+solve(i+1,j+1,t1,t2,dp);
        }
        int f1=solve(i+1,j,t1,t2,dp);
        int f2=solve(i,j+1,t1,t2,dp);
        dp[i][j]= max(inc,max(f1,f2));
        return dp[i][j];
    }
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>>dp(text1.size()+1,vector<int>(text2.size()+1,-1));
        return solve(0,0,text1,text2,dp);
    }
};
