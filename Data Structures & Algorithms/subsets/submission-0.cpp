class Solution {
public:
    void solve(int i,vector<int>& nums,vector<int>temp,vector<vector<int>>&ans){
       
        if(i>=nums.size()){
            return;
        } 
        solve(i+1,nums,temp,ans);
    
        temp.push_back(nums[i]);
        solve(i+1,nums,temp,ans);
        ans.push_back(temp);

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp;
       ans.push_back(temp);
        solve(0,nums,temp,ans);
        return ans;
    }
};
