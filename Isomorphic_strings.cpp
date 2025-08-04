// class Solution {
// public:
//     bool isIsomorphic(string s, string t) {
//         unordered_map<char,char> m;
//         for( int i =0; i<s.length() ; i++){
//             if(m.find(s[i]) == m.end()){
//                 m[s[i]]= t[i];
//             }
//             else{
//                 if(m[s[i]] != t[i]){
//                     return false;
//                 }
//             }
//         }

//         // for( int i =0; i<t.length() ; i++){
//         //     if(m.find(t[i]) == m.end()){
//         //         m[t[i]]= s[i];
//         //     }
//         //     else{
//         //         if(m[t[i]] != s[i]){
//         //             return false;
//         //         }
//         //     }
//         // }

//         return true;
//     }
// };

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length()) return false;

        unordered_map<char, char> m1;
        unordered_map<char, char> m2;

        for (int i = 0; i < s.length(); i++) {
            char c1 = s[i], c2 = t[i];

            // If mapping already exists, it must be consistent
            if (m1.count(c1)) {
                if (m1[c1] != c2) return false;
            } else {
                m1[c1] = c2;
            }

            // Also check reverse mapping to ensure one-to-one
            if (m2.count(c2)) {
                if (m2[c2] != c1) return false;
            } else {
                m2[c2] = c1;
            }
        }

        return true;
    }
};
