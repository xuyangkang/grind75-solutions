class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> last_seen;
        vector<int> ans;
        for (size_t i = 0; i < nums.size(); i++) {
            int num = nums[i];
            int diff = target - num;
            auto it = last_seen.find(target - num);
            if (it != last_seen.end()) {
                ans.push_back(it->second);
                ans.push_back(i);
                break;
            }
            last_seen[num] = i;
        }
        return move(ans);
    }
};
