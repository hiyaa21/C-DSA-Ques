class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map <char,int> m1;
        unordered_map <char,int> m2;

        if(s.length()!= t.length()) return false;

        for(int i=0; i<s.length(); i++){
                m1[s[i]]++;
        }
        for(int i=0; i<t.length(); i++){
            if(m1.count(t[i])){
                m1[t[i]]--;
            }
            else{
                return false;
            }
        }

        for(auto pair : m1){
            if(pair.second != 0) return false;
        }

        return true;



    }
};