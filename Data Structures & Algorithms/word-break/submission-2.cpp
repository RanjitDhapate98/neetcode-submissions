class Solution {
public:
    bool solve(int i,string s, vector<string>& nums,vector<int>&dp){
        if(i==s.size()){
            return true;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        for(int j=i+1;j<=s.size();j++){
            string temp=s.substr(i,j-i);
            for(auto a:nums){
                if(temp==a){
                    bool ans=solve(j,s,nums,dp);
                    if(ans==true){
                        dp[i]=true;
                        return dp[i];

                    }
                }
            }
            
        }
        dp[i]=false;
        return dp[i];
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int>dp(s.size()+1,-1);
      return solve(0,s,wordDict,dp);  
    }
};
