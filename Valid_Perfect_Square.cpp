class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num==1)return true;

        int st=1;
        int end= num/2;

        while(st<=end){
        int mid= st + (end-st)/2;

        // multiplying can make the value overflow so long long conversion is used.
        long long sq = 1LL* mid * mid;


        if(sq > num){
            end= mid-1;
        }
        else if(sq == num){
            return true;
        }
        else{
            st= mid+1;
        }
        }
        return false;
    }
};