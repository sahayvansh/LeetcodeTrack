class MinStack {
    stack<long long> st;
    long long mini;
public:
    MinStack() {
    while (!st.empty()) st.pop();
      mini = INT_MAX;
    }
    
    void push(int val) {
        long long value=(long long) val;
        if(st.empty()){
            mini=value;
            st.push(mini);
        }
        else{
            if(value<mini){
                st.push(2*value-mini);
                mini=value;
            }
            else{
                st.push(value);
            }
        }
    }
    
    void pop() {
        if (st.empty()) return;
        long long n=st.top();
        st.pop();
        if(n<mini){
            mini=2*mini-n;
        }
    }
    
    int top() {
        if(st.empty())
            return -1;
        long long n=st.top();
        if(n<mini)
            return mini;
        else
            return n;
    }
    
    int getMin() {
        return mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */