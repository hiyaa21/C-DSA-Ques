class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
         unordered_map<int, int> lastSeen; // number -> last index

        for (int i = 0; i < nums.size(); i++) {
            if (lastSeen.find(nums[i]) != lastSeen.end() && i - lastSeen[nums[i]] <= k) {
                return true; // found duplicate within k distance
            }
            lastSeen[nums[i]] = i; // update last index
        }
        return false;
    }
};