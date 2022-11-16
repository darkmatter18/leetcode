/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        return guess_helper(1, n);
    }
    
    int guess_helper(int l, int h){
        int m = (int)(((double)l + (double)h) / 2);
        int a = guess(m);
        
        cout << l << " " << h << " " << m << " " << a << endl;
        
        if(a == 1){
            // check lower side
            return guess_helper(m+1, h);
        } else if(a == -1){
            // check the lower side
            return guess_helper(1, m-1);
        } else if(a == 0){
            return m;
        } else {
            return 0;
        }
    }
};