class MyStack {
public:
    queue<int> q;
    queue<int> r;

    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
    }
    
    int pop() {
        
        int x = -1;
        if(q.empty()) return x;

        
        while(!q.empty())
        {
            x = q.front();
            q.pop();
            if(q.size() >0) r.push(x);
        }

        while(!r.empty())
        {
            q.push(r.front());
            r.pop();
        }

        return x;
    }
    
    int top() {

        int x = -1;
        if(q.empty()) return x;

        while(!q.empty())
        {
            x = q.front();
            q.pop();
            r.push(x);
        }

        while(!r.empty())
        {
            q.push(r.front());
            r.pop();
        }

        return x;
        
    }
    
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */