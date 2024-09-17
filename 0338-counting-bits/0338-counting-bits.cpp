class Solution {
public:
    vector<int> countBits(int n) {
        int i = 0, last;
        vector<int> res(n+1);
        
        last = 2;
        while(i <= n){
            if(i==0) {
                res[0] = 0;
                i++;
                continue;
            }
            if(i==1){
                res[1] = 1;
                i++;
                continue;
            }
            
            for(int k=0; k<last && i <= n; k++, i++){
                // cout << last+k << " " << i << " " << k << endl;
                res[last+k] = res[k]+1;
            }
            last *= 2;
            // cout << "Out loop" << endl;
        }
        
        return res;
    }
};