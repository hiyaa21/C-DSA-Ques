class Solution {
public:
    void permu(vector<int>& nums, int idx, vector<vector<int>>& final){
        if(idx==nums.size()){
            final.push_back({nums});
        }
        // forward
        for(int i=idx; i<nums.size(); i++){
            swap(nums[idx], nums[i]);
            permu(nums, idx+1, final);

            // Backtracking
            swap(nums[idx], nums[i]);
        }
        
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>final;
        permu(nums, 0, final);
        return final;
    }
};