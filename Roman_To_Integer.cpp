class Solution {
public:
    int romanToInt(string s) {
        
        int value=0;
        for(int i=0; i<s.length(); i++){
            char c= s[i];
            switch(c){
                case 'I':
                {
                if(s[i+1]!='I'){
                    value-=1;
                }
                else if(i==s.length()-1){
                    value +=1;
                }
                else{
                    value +=1;
                }
                }
                case 'V':{
                    if(s[i+1]=='I' || s[i+1]=='V'){
                        value +=5; 
                    }
                    else {
                        value-=5;
                    }
                }
                case 'X':{
                    if(s[i+1]=='I' || s[i+1]=='V' || s[i+1]=='X'){
                        value +=10;
                    }
                    else{
                        value -=10;
                    }
                }
                case 'L':{
                    if(s[i+1]=='I' || s[i+1]=='V' || s[i+1]=='X' || s[i+1]=='L'){
                        value +=50;
                    }
                    else{
                        value -=50;
                    }
                }
                case 'C':{
                    if(s[i+1]=='I' || s[i+1]=='V' || s[i+1]=='X' || s[i+1]=='L' || s[i+1]=='C'){
                        value +=100;
                    }
                    else{
                        value -=100;
                    }
                }
                case 'D':{
                    if(s[i+1]=='I' || s[i+1]=='V' || s[i+1]=='X' || s[i+1]=='L' || s[i+1]=='C' || s[i+1]=='D']){
                        value +=500;
                    }
                    else{
                        value -=500;
                    }
                }
                case 'M':{
                    if(s[i+1]=='I' || s[i+1]=='V' || s[i+1]=='X' || s[i+1]=='L' || s[i+1]=='C' || s[i+1]=='D' || s[i+1]=='M'){
                        value +=1000;
                    }
                    else{
                        value -=1000;
                    }
                }
                
            }
            
    }
};