class Solution {
public:
    int minimumSum(int num) {
        int idx;
        int m1 = INT_MAX;
        int m2 = INT_MAX;
        int m3 = INT_MAX;
        int m4 = INT_MAX;
        
        vector<int> n;
        vector<int>::iterator it;
        
        
        
        while(num > 0){
            n.push_back(num % 10);
            num /= 10;
        }
        
        for(int i = 0; i < n.size(); i++){
            if(m1 > n[i]){
                idx = i;
                m1 = n[i];
            }
        }
        it = n.begin();
        n.erase(it+idx);
        
        // cout << m1 << endl;
        
        for(int i = 0; i < n.size(); i++){
            if(m2 > n[i]){
                idx = i;
                m2 = n[i];
            }
        }
        it = n.begin();
        n.erase(it+idx);
        
        // cout << m2 << endl;
        
        for(int i = 0; i < n.size(); i++){
            if(m3 > n[i]){
                idx = i;
                m3 = n[i];
            }
        }
        it = n.begin();
        n.erase(it+idx);
        
        // cout << m3 << endl;
        
        m4 = n[0];
        
        // cout << m4 << endl;
        
        return m1*10+m2*10+m3+m4;
        
    }
};