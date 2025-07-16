class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
        vector<int> ans;
        int n = arr.size();

        int i=0, j=n-1;
        while(i<j){
            int pairSum = arr[i] + arr[j];
            if(pairSum > target){
                j--;
            } else if(pairSum < target){
                i++;
            } else{
                ans.push_back(i+1);
                ans.push_back(j+1);
                return ans;
            }
        }

        return ans;
        
    }
};