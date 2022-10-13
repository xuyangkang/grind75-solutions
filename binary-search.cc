class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if (nums[0] > target) {
            return -1;
        }
        
        if (nums[n - 1] <= target) {
            return nums[n - 1] == target ? n - 1 : -1;
        }
        
        int l = 0;
        int r = n - 1;
        while (l + 1 < r) {
            int mid = (l + r) / 2;
            if (nums[mid] <= target) {
                l = mid;
            } else {
                r = mid;
            }
        }
        
        return nums[l] == target ? l : -1;
    }
};
