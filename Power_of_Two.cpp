class Solution {
public:
    bool isPowerOfTwo(int n) {

        if(n==0) return false;
       //log base 2

       double ans= log2(n);
       double x= ans;

        if (x == floor(x))
            return true;
        else
            return false;
        
        
    }
};