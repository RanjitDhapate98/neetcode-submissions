class Solution {
public:
    void solve(int i,int sum,vector<int>& nums, int target,vector<int>temp,vector<vector<int>>&ans){
        if(i>=nums.size()){
            
            return ;
        }
        if(sum==target){
                ans.push_back(temp);
                return ;
            }
        if(sum+nums[i]<=target){
            sum+=nums[i];
            temp.push_back(nums[i]);
            solve(i,sum,nums,target,temp,ans);
            temp.pop_back();
            sum-=nums[i];
        }
        solve(i+1,sum,nums,target,temp,ans);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int>temp;
        vector<vector<int>>ans;
        solve(0,0,nums,target,temp,ans);
        return ans;
    }
};
