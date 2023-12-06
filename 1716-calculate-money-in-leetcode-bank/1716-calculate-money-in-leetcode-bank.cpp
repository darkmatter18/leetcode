class Solution {
public:
    int week_wise(int n, int i){
        if(n==0) return 0;
        if(n==1) return 1 + i;
        if(n==2) return 3 + 2*i;
        if(n==3) return 6 + 3*i;
        if(n==4) return 10 + 4*i;
        if(n==5) return 15 + 5*i;
        if(n==6) return 21 + 6*i;
        return 28 + 7*i;
        
        
    }
    int totalMoney(int n) {
        int total = 0, i = 0;
        
        while(n > 7){
            // cout << week_wise(7, 0) << endl;
            total += week_wise(7, i);
            n-=7;
            i++;
        }
  
        total +=  week_wise(n, i);
        // cout << week_wise(n, i) << endl;
        
        return total;
    }
};