class Solution {
public:
    int solve(int i,string s,vector<int>&dp){
        
        if(i==s.size()){
            return 1;
        }
        if(i>s.size()){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        if(s[i]=='0'){
            return 0;
        }
        int one=solve(i+1,s,dp);
        int two=0;
        if(i<s.size()-1){
           int z=(s[i]-'0')*10+(s[i+1]-'0');
           if(z<=26){
            two=solve(i+2,s,dp);
           }
        }
        dp[i]=one+two;
        return one+two;
    }
    int numDecodings(string s) {
        vector<int>dp(s.size()+1,-1);
        return solve(0,s,dp);
    }
};
