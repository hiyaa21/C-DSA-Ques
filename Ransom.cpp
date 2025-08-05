class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {

        if(magazine.length()<ransomNote.length()) return false;

        unordered_map <char, int> m1;
        
        for(auto x: magazine){
            m1[x]++;
        }

        for(auto x: ransomNote){
            if(!m1.count(x)) return false;
            else{
                m1[x]--;
            }
        }

        for(auto pair : m1){
            if(pair.second < 0) return false;
        }

        return true;

    }
};