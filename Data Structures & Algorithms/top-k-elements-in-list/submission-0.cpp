class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>freq;
        for(auto i:nums){
            freq[i]++;
        }
        using a=pair<int,int>;
        priority_queue<a,vector<a>,greater<a>>pq;
        for(auto i:freq){
            int num=i.first;
            int f=i.second;
            if(k>0){
                pq.push({f,num});
                k--;
            }else{
                auto top=pq.top();
               
                int ct=top.first;
                if(ct<f){
                    pq.pop();
                    pq.push({f,num});
                }
            }

        }
        vector<int>ans;
        while(!pq.empty()){
         ans.push_back(pq.top().second);
         pq.pop();

        }
        return ans;
    }
};
