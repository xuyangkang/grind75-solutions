class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> last_seen;
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            const auto &it = last_seen.find(target - num);
            if (it != last_seen.end()) {
                return {it->second, i};
            }
            last_seen[num] = i;
        }
        return {};
    }
};