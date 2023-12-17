class MedianFinder {
    priority_queue<int> max_pq;
    priority_queue<int, vector<int>, greater<int>> min_pq;
        
public:
    MedianFinder() {
      
    }
    
    void addNum(int num) {
        if(max_pq.empty() && min_pq.empty()){
            max_pq.push(num);
            return;
        }
        
        if(num > max_pq.top())
            min_pq.push(num);
        else
            max_pq.push(num);
        
        if(abs((int)(max_pq.size() - min_pq.size())) > 1){
            if(max_pq.size() > min_pq.size()){
                int i = max_pq.top();
                max_pq.pop();
                min_pq.push(i);
            }
            else {
                int i = min_pq.top();
                min_pq.pop();
                max_pq.push(i);
            }
        }
    }
    
    double findMedian() {
        if(max_pq.size() == min_pq.size()){
            return (double)(max_pq.top() + min_pq.top()) / 2;
        }
        else if(max_pq.size() > min_pq.size()){
            return max_pq.top();
        }
        else {
            return min_pq.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */