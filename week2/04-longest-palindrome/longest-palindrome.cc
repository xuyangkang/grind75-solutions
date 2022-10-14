class Solution {
public:
    int longestPalindrome(string s) {
        int char_count[128] = {0};
        for (char ch : s) {
            char_count[ch]++;
        }
        int ans = 0;
        bool center = false;
        for (int ch = 0; ch < 128; ch++) {
            ans += char_count[ch] / 2 * 2;
            if (char_count[ch] % 2) {
                center = true;
            }
        }
        if (center) {
            ans++;
        }
        return ans;
    }
};