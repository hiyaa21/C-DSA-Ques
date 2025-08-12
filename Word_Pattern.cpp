class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map <char,int> m1;
        unordered_map <string,int> m2;

        // converts a spaced string into string stream
        // "dog cat cat dog" -> "dog", "cat", "cat", "dog"
        istringstream iss(s);
        string word;

        int i=0;

        for(auto x: pattern){
            // s is less than pattern.
            // iss>>word means next word 
            if(!(iss >> word)) return false;

            // In map keys by default gets when inserted gets 0 value 
            if(m1[x] != m2[word]){
                return false;
            }

            m1[x] = m2[word] = i+1;
            i++;
        }

        // if s is bigger than pattern
        if(iss>>word) return false;

        return true;
        
    }
};