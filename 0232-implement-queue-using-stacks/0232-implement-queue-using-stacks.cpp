class MyQueue {
    stack<int> s;
    
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        s.push(x);
    }
    
    int pop() {
        stack<int> s2;
        copy_reverse(s, s2);
        int el = s2.top();
        s2.pop();
        copy_reverse(s2, s);
        return el;
        
    }
    
    int peek() {
        stack<int> s2;
        s2 = s;
        int p;
        while(s2.size() > 0){
            p = s2.top();
            s2.pop();
        }
        return p;
    }
    
    bool empty() {
        return s.empty();
    }
    
    template<typename T=int>
    void copy_reverse(stack<T>& source, stack<T>& dest){
        while(!source.empty()){
            dest.push(source.top());
            source.pop();
        }
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