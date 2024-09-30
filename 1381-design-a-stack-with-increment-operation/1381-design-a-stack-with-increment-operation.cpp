class CustomStack {
    vector<int> stack;
    int length;
    int currIdx;
    
public:
    CustomStack(int maxSize) {
        stack.resize(maxSize);
        length = maxSize;
        currIdx = 0;
    }
    
    void push(int x) {
        if(currIdx < length){
            stack[currIdx] = x;
            currIdx++;
        }
    }
    
    int pop() {
        if(currIdx <= 0){
            return -1;
        }
        int s = stack[currIdx-1];
        currIdx--;
        return s;
    }
    
    void increment(int k, int val) {
        int maxLoop = min(k, currIdx);
        for(int i=0; i < maxLoop; i++){
            stack[i] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */