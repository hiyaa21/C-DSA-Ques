class Solution {
public:

    set<vector<int>>s;
    void value(vector<vector<int>>& final, vector<int>& ans, int i, int target, vector<int>& arr ){
        // base case
        if(target==0){
            if(s.find(ans) == s.end())
            final.push_back({ans});
            s.insert(ans);
            return;
        }
        if(i==arr.size() || target<0){
            return;
        }

        // included single
        ans.push_back(arr[i]);
        value(final, ans, i+1, target-arr[i], arr);

        value(final, ans, i, target-arr[i], arr);

        // backtrack
        ans.pop_back();

        // excluded 
        value(final, ans, i+1, target, arr);

    }

    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        vector<int>ans;
        vector<vector<int>>final;
        value(final, ans, 0, target, arr);
        return final;
    }
};