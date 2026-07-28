class Solution {
public:
    void solve(int i,vector<int>& nums,vector<vector<int>>&ans,vector<int>&temp){
        if(i==nums.size()-1){
             ans.push_back(temp);
            return;
        }
        for(int j=i;j<nums.size();j++){
            swap(temp[i],temp[j]);
            solve(i+1,nums,ans,temp);
            swap(temp[i],temp[j]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp=nums;
        solve(0,nums,ans,temp);
        return ans;
    }
};
