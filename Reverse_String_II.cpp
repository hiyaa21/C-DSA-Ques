class Solution {
public:
// Always pass by reference for permanent change in string
    string reverseee(string& s, int st, int end){
        int i=st;
        int j= end;
        while(i<j){
            swap(s[i], s[j]);
            i++;
            j--;
        }
        return s;

    }

    string reverseStr(string s, int k) {
        int i=0;
        int n= s.size();
        while(i<n){
            int end = min(i+k-1, n-1);
            reverseee(s, i, end);
            i+= k*2;
        }
        return s;
    }
};