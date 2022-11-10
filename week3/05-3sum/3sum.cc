class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            int k = n - 1;
            for (int j = i + 1; j < n; j++) {
                int sum = nums[i] + nums[j];
                while (k > j && sum + nums[k] > 0) {
                    k--;
                }
                if (j < k && sum + nums[k] == 0) {
                    ans.push_back({nums[i], nums[j], nums[k]});
                } 

                while (j + 1 < n && nums[j] == nums[j + 1]) {
                    j++;
                }
            }
            while (i + 1 < n && nums[i] == nums[i + 1]) {
                i++;
            }
        }
        return ans;
    }
};