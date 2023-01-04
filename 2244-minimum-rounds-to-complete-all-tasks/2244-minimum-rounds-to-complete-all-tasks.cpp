class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        map<int, int> m;
        
        for(int t: tasks){
            if(m.find(t) == m.end()){
                m.insert(pair<int, int>(t, 1));
            }else {
                m[t]++;
            }
        }
        
        int a = 0;
        for(auto x:m){
            // TODO
            int l = x.second;
            cout << x.first << " " << l << endl;
            while(l > 0){
                if(l == 1){
                    return -1;
                }
                else if(l == 2 || l == 3){
                    a++;
                    break;
                }
                else if(l == 4){
                    a += 2;
                    break;
                }
                else {
                    l -= 3;
                    a++;
                }
                // if(l % 3 == 0){
                //     a += (l/3);
                //     break;
                // }
                // else if(l % 2 == 0){
                //     a += (l/2);
                //     break;
                // } 
                // else if(l > 3){
                //     a++;
                //     l -= 3;
                // }
                // else if(l > 2){
                //     a++;
                //     l -= 2;
                // }
                // else {
                //     return -1;
                // }
            }
            
        }
        return a;
    }
};