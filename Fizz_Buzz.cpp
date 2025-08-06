class Solution {
public:
    bool three(int n){
        return n%3==0 ? true: false;
    }

    bool five(int n){
        return n%5==0 ? true: false;
    }

    vector<string> fizzBuzz(int n) {
        vector<string> answer;

        for(int i=1; i<=n; i++){
            if(three(i) && five(i)){
                answer.push_back("FizzBuzz");
            }
            else if(three(i)){
                answer.push_back("Fizz");
            }
            else if(five(i)){
                answer.push_back("Buzz");
            }
            else{
                string s = to_string(i);
                answer.push_back(s);
            }
        }

        return answer;

    }
};