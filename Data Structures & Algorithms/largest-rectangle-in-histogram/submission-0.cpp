class Solution {
public:
    int largestRectangleArea(vector<int>& nums) {
        vector<int>next;
        vector<int>prev;
        stack<int>st;
        for(int i=0;i<nums.size();i++){
           while(!st.empty() && nums[st.top()]>=nums[i]){
            st.pop();
           }
           if(st.empty()){
            prev.push_back(-1);
           }else{
            prev.push_back(st.top());
           }
           st.push(i);
        }
        stack<int>st1;
        int n=nums.size();
        for(int i=nums.size()-1;i>=0 ;i--){
           while(!st1.empty() && nums[st1.top()]>=nums[i]){
            st1.pop();
           }
           if(st1.empty()){
            next.push_back(n);
           }else{
            next.push_back(st1.top());
           }
           st1.push(i);
        }
        reverse(next.begin(),next.end());
        int ans=INT_MIN;
        for(int i=0;i<nums.size();i++){
         ans=max(ans,(next[i]-prev[i]-1)*nums[i]);
        }
        return ans;
    }
};
