class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i=0;
        int j=nums.size()-1;
        while(i<j){
            while(i<nums.size()-1 && nums[i]==nums[i+1]){
                i++;
            }
            while(j>0 && nums[j]==nums[j-1]){
                j--;
            }
            if(nums[i]+nums[j]==target){
                return {i+1,j+1};
            }
            if(nums[i]+nums[j]<target){
                i++;
            }else{
                j--;
            }
        }
       return {-1,-1};
    }
};
