class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        vector<int>ans;

        for(int i=0; i<nums.size();i++){
            int first= nums[i];
            int sec= target- first;

            if(m.find(sec)!=m.end()){
                ans.push_back(i);
                ans.push_back(m[sec]);
                break;
            }

            m[first]=i;
        }
        return ans;

        // int lp= 0 ;
        // int rp= nums.size()-1;

        // if(nums[lp]+nums[rp]==target){
        //     return {lp,rp};
        // }
        // else{
        //     if(nums[lp]>target){
        //         lp++;
        //     }
        //     if(nums[rp]>target){
        //         rp--;
        //     }
        // }

        // while(lp<rp){
        //     if(nums[lp]+nums[rp]==target){
        //     return {lp,rp};
        // }
        // }
        // return{};
    }
};