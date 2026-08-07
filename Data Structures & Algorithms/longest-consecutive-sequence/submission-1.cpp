class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>store(nums.begin(),nums.end());
        int ans=0;
        int curr=0;
        for(auto i:nums){
            curr=0;
           if(store.find(i-1)==store.end()){
             
             int temp=i;
             while(store.find(temp)!=store.end()){
              temp++;
              curr++;
             }
           }
           ans=max(ans,curr);

        }
        return ans;
    }
};
