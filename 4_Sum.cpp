class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n =  nums.size();
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());

        int p1=0,p2=0;
        long long sum=0;

        for(int i=0; i<n; i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            for(int j=i+1; j<n; ){
                p1= j+1;
                p2= n-1;
                while(p1<p2){
                    sum= (long long)nums[i]+ (long long)nums[j]+ (long long)nums[p1]+ (long long)nums[p2];
                    if(sum<target) p1++;
                    else if(sum>target) p2--;
                    else {
                        ans.push_back({nums[i], nums[j], nums[p1], nums[p2]});
                        p1++, p2--;

                        while(p1<p2 && nums[p1]==nums[p1-1]) p1++;
                    }
                }
            j++;
            while(j<n && nums[j]==nums[j-1]) j++;
            }
        }
        return ans;
    }
};