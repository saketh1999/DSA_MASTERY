class MyQueue {
public:
stack<int> inp;
        stack<int> out;
    MyQueue() {
        
    }
    
    void push(int x) {
        inp.push(x);

    }
    
    int pop() {
        int x;
        if(out.empty()==false)
        {
            x= out.top();
            out.pop();
        }
       
        else
        {
            while(inp.empty()==false)
            {
                out.push(inp.top());
                inp.pop();
            }
             x= out.top();
            out.pop();
            
        }
        return x;
    }
    
    int peek() {
        int x;
        if(out.empty()==false)
        {
            x= out.top();
            
        }
       
        else
        {
            while(inp.empty()==false)
            {
                out.push(inp.top());
                inp.pop();
            }
             x= out.top();
            
            
        }
        return x;
    }
    
    bool empty() {
        if(out.empty() == true && inp.empty()==true)
        return true;
        else
        return false;
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