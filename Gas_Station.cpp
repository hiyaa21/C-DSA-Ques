class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n= gas.size();
        int currgas=0;
        int sumg=0;
        int sumc=0;
        // find if ans is possible;
        for(int i=0; i<n; i++){
            sumg+= gas[i];
            sumc+= cost[i];
        }
        
        if(sumg<sumc){
            return -1;
        }
        
        int ans =0;
        for(int i=0; i<n; i++){
            currgas= currgas + gas[i]- cost[i];
            if(currgas<0){
                ans= i+1;
                currgas=0;
            }
        }

        return ans;
        
    }
};