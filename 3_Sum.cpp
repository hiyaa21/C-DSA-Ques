class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n =  nums.size();
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());

        int p1=0,p2=0, sum=0;

        for(int i=0; i<n; i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            p1= i+1;
            p2= n-1;
            while(p1<p2){
                sum= nums[i]+nums[p1]+nums[p2];
                if(sum<0){
                    p1++;
                }
                else if(sum>0){
                    p2--;
                }
                else {
                    ans.push_back({nums[i], nums[p1], nums[p2]});
                    p1++, p2--;

                    while(p1<p2 && nums[p1]==nums[p1-1]) p1++;
                }
            }
        }
        return ans;
    }
};