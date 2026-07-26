class Solution {
public:
    bool searchMatrix(vector<vector<int>>& nums, int target) {
        int i=0;
        int a=nums.size();
        int b=nums[0].size();
        int j=a*b-1;
        while(i<=j){
         int mid=i+(j-i)/2;
         int row=mid/b;
         int col=mid%b;
         if(nums[row][col]==target){
            return true;
         }
         if(nums[row][col]>=target){
           j=mid-1; 
         }else{
            i=mid+1;
         }
        }
        return false;
    }
};
