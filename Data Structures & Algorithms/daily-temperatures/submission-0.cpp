class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& nums) {
        stack<int>st;
        vector<int>ans;
        for(int i=nums.size()-1;i>=0 ;i--){
           while(!st.empty() && nums[st.top()]<=nums[i]){
            st.pop();
           }
           if(st.empty()){
            ans.push_back(0);
           }else{
             int temp=st.top()-i;
             ans.push_back(temp);
           }
           st.push(i);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
