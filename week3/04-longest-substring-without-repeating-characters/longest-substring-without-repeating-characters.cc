class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int ans = 0;
        int l = 0;
        int r = 0;
        bool seen[128] = {};
        while (r < n) {
            while (seen[s[r]]) {
                seen[s[l]] = false;
                l++;
            }
            seen[s[r]] = true;
            ans = max(ans, r - l + 1);
            r++;
        }
        return ans;
    }
};