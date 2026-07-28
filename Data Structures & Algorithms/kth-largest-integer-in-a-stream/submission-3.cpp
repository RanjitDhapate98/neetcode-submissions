class KthLargest {
    priority_queue<int,vector<int>,greater<int>>pq;
public:
   int a=0;
    KthLargest(int k, vector<int>& nums) {
        a=k;
        for(int i=0;i<nums.size();i++){
            if(a>0){
                pq.push(nums[i]);
                a--;
            }else{
                auto top=pq.top();
                if(top<nums[i]){
                pq.pop();
                pq.push(nums[i]);
                }
            }
        }
    }
    
    int add(int val) {
        if(a>0){
                pq.push(val);
                a--;
            }else{
                auto top=pq.top();
                if(top<val){
                pq.pop();
                pq.push(val);
                }
            
        }
        return pq.top();
    }
};
