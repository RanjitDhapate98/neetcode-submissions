class MedianFinder {
    priority_queue<int>pq;
    priority_queue<int,vector<int>,greater<int>>pq1;
public:

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        pq.push(num);
        auto top=pq.top();
        pq.pop();
        pq1.push(top);
        while(pq1.size()>pq.size()){
            auto top=pq1.top();
            pq1.pop();
            pq.push(top);
        }
    }
    
    double findMedian() {
        if(pq.size()!=pq1.size()){
            return pq.top();
        }
        return double(pq.top()+pq1.top())/2.0;
    }
};
