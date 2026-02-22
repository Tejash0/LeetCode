class MinStack {
public:
    stack<int> s1;
    stack<int> mini;
    MinStack() {
        
    }
    
    void push(int val) {
        if(mini.empty())
        {
            s1.push(val);
            mini.push(val);
        }
        else
        {
            s1.push(val);
            val = min(val,mini.top());
            mini.push(val);
        }
    }
    
    void pop() {
        s1.pop();
        mini.pop();
    }
    
    int top() {
        return s1.top();
    }
    
    int getMin() {
        return mini.top();
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