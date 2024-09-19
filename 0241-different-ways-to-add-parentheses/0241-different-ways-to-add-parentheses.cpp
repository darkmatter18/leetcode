class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        // cout << expression << endl;
        
        vector<int> res;
        if(expression.size() == 0) return res;
        
        unordered_set<char> opt({'+', '-', '*'});
        int pos = 0;
        
        int optCount = 0;
        while(pos < expression.size()){
            if(opt.contains(expression[pos])){
                optCount++;
            }
            pos++;
        }

        if(optCount == 0){
            res.push_back(stoi(expression));
            return res;
        }
        pos = 0;
        
        while(optCount--){
            // find the next exp
            while(pos < expression.size() && !opt.contains(expression[pos])){
                pos++;
            }
            
            vector<int> vexp1 = diffWaysToCompute(expression.substr(0, pos));
            vector<int> vexp2;
            vector<int> vres;
            
            if(pos < expression.size()){
                vexp2 = diffWaysToCompute(expression.substr(pos+1));
            
                // compute
                for(int n1 : vexp1){
                    for(int n2 : vexp2){
                        switch(expression[pos]){
                            case '+':
                                vres.push_back(n1+n2);
                                break;
                            case '-':
                                vres.push_back(n1-n2);
                                break;
                            case '*':
                                vres.push_back(n1*n2);
                                break;
                        }
                    }
                }
                
            }
            else {
                vres = vexp1;
            }
            pos++;
            res.insert(res.end(), vres.begin(), vres.end());
        }
        
        return res;
    }
};