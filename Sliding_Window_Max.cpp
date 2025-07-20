class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> d;
        vector<int> v;

        // first window
        for(int i=0; i<k; i++){
            while(d.size()>0 && nums[d.back()] < nums[i]){
                d.pop_back();
            }
            d.push_back(i);
        }

        for(int i=k; i<nums.size(); i++){
            v.push_back(nums[d.front()]);
            
            // Remove that is not in window
            while(d.size()>0 && d.front()<= i-k){
                d.pop_front();
            }

            // Remove smaller values
            while(d.size()>0 && nums[d.back()] < nums[i]){
                d.pop_back();
            }

            d.push_back(i);
        }
        // for last value
        v.push_back(nums[d.front()]);
        return v;
    }
};