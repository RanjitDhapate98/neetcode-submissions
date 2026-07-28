class Solution {
public:
    void solve(int i,int sum,vector<int>& nums, int target,vector<int>&temp,vector<vector<int>>&ans){
        
         if(sum==target){
                ans.push_back(temp);
                return ;
            }
        if(i>=nums.size()|| sum>target ){
            
            return ;
        }
       
        
            sum+=nums[i];
            temp.push_back(nums[i]);
            solve(i+1,sum,nums,target,temp,ans);
            temp.pop_back();
            sum-=nums[i];
        
        while(i<nums.size()-1&& nums[i]==nums[i+1]){
            i++;
        }
        solve(i+1,sum,nums,target,temp,ans);
    }
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        vector<int>temp;
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        solve(0,0,nums,target,temp,ans);
        return ans;
    }
};
