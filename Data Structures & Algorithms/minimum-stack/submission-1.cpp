class MinStack {
   stack<pair<int,int>>st;
 
public:
    MinStack() {
        
    }
    
    void push(int val) {
      if(st.empty()){
         st.push({val,val});
      }
      else{
         
          st.push({val,min(st.top().second,val)});
      }
        
    }
    
    void pop() {
      if(!st.empty()){
       
       st.pop(); 
       }
    }
    
    int top() {
      if(!st.empty()){
        auto top=st.top();
        return top.first;
        }
        return -1;
    }
    
    int getMin() {
        auto top=st.top();
        return top.second;
    }
};
