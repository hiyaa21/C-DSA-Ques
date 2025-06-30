class Solution {
public:
    bool isValid(string s) {
       stack <char> b;
       int count=0;
            for(int i=0; i<s.length(); i++){
                if(s[i]=='(' || s[i]=='{' || s[i]== '['){
                    b.push(s[i]);
                }else {
                        if(b.empty()) {
                        return false;
                        }else {
                            if((s[i]==')' && b.top() =='(') || 
                            (s[i]==']' && b.top() =='[') || 
                            (s[i]=='}' && b.top() =='{')) {
                                b.pop();
                            }else{
                                return false;
                            }
                        }
                }
            }
        if (!b.empty() ) {
            return false;
        }
        return true;
    }
};