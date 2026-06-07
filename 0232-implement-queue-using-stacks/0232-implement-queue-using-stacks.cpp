class MyQueue {
public:
        stack<int> s;
        stack<int> p;
    MyQueue() {
        
    }
    
    void push(int x) {

        s.push(x);
        
    }
    
    int pop() {

        while(!s.empty()) 
        {
            p.push(s.top());
            s.pop();
        }
        int x = p.top();
        p.pop();
        while(!p.empty())
        {
            s.push(p.top());
            p.pop();
        }
        return x;
        
    }
    
    int peek() {

        while(!s.empty()) 
        {
            p.push(s.top());
            s.pop();
        }
        int x = p.top();
        while(!p.empty())
        {
            s.push(p.top());
            p.pop();
        }
        return x;


        
    }
    
    bool empty() {
        return s.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */