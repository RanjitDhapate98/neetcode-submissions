class Solution {
public:
    int trap(vector<int>& nums) {
        int n=nums.size();
        if(n==0){
         return 0;

        }
        int ans=0;
        vector<int>next(n);
        vector<int>prev(n);
        next[0]=nums[0];
        for(int i=1;i<next.size();i++){
           next[i]=max(next[i-1],nums[i]);
        }
        prev[n-1]=nums[n-1];
        for(int i=n-2;i>=0; i--){
           prev[i]=max(prev[i+1],nums[i]);
        }
        for(int i=0;i<nums.size();i++){
         ans+=min(next[i],prev[i])-nums[i];
        }
        return ans;
    }
};
