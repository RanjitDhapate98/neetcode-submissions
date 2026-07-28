class Solution {
public:
    int lastStoneWeight(vector<int>& nums) {
        priority_queue<int>pq;
        for(auto i:nums){
            pq.push(i);
        }
        while(pq.size()>1){
            auto top1=pq.top();
            pq.pop();
            auto top2=pq.top();
            pq.pop();
            int temp=abs(top1-top2);
           
                pq.push(temp);
            
        }
        return pq.top();
    }
};
