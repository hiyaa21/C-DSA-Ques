class Solution {
public:
    int count(int num){
        int count=0;
        if(num>0){
            num/=10;
            count++;
        }
        return count;
    }
    int number(int num, int n){
        for(int i=1; i<n; i++){
            num= num/10;
        }
        return num%10;
    }
    bool isPalindrome(int x) {

        if(x<0 || (x%10==0 && x!=0)){
            return false;
        }

        int n= count(x);


        for(int i=1; i<=n; i++){
            if(number(x,i)!=number(x,n-i +1)){
                return false;
            }
        }
        return true;
    }
};