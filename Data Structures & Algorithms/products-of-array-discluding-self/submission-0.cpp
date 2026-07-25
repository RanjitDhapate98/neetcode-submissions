class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
           vector<int>suf;
           int temp=1;
           for(int i=nums.size()-1;i>=0;i--){
               temp*=nums[i];
               suf.push_back(temp);
               
           }
           reverse(suf.begin(),suf.end());
           vector<int>ans;
           int curr=1;
           for(int i=0;i<nums.size()-1;i++){
                ans.push_back(suf[i+1]*curr);
                curr*=nums[i];
              
           }
           ans.push_back(curr);
           return ans;
    }
};
