class Solution {
public:
    int maxProfit(vector<int>& nums) {
       int buy=nums[0];
       int ans=INT_MIN;
       for(auto i:nums){
        buy=min(buy,i);
        ans=max(ans,i-buy);
       }
       return ans;
    }
};
