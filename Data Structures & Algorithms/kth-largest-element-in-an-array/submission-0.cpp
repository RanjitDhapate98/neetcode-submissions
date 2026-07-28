class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>>pq;
        for(auto i:nums){
            if(k>0){
                pq.push(i);
                k--;
            }else{
                auto top=pq.top();
                if(top<i){
                    pq.pop();
                    pq.push(i);
                }
            }

        }
        return pq.top();
    }
};
