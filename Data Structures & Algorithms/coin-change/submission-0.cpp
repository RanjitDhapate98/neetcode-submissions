class Solution {
public:
   int ans=INT_MAX;
    void solve(int i,vector<int>& coins, int amount,int curr,int c){
        if(i>=coins.size()){
            return;
        }
        if(curr==amount)
        {
            ans=min(ans,c);
            return;
        }
    
           
            if(curr+coins[i]<=amount){
           
                solve(i,coins,amount,curr+coins[i],c+1);
            
            }
           
        
         solve(i+1,coins,amount,curr,c);
    }
    int coinChange(vector<int>& coins, int amount) {
         solve(0,coins,amount,0,0);
         if(ans==INT_MAX){
            return -1;
         }
         return ans;
    }
};
