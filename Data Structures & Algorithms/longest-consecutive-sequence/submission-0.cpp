class Solution {
public:
    int solve(int i,int prev,vector<int>& nums){
        if(i>=nums.size()){
            return 0;
        }
        int inc=0;
        if(prev==INT_MIN || nums[prev]+1==nums[i]){
            inc=1+solve(i+1,i,nums);
        }
        int exc=solve(i+1,prev,nums);
        return max(inc,exc);
    }
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        return solve(0,INT_MIN,nums);
    }
};
