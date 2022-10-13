class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_seen = prices[0];
        int ans = 0;
        for (int p : prices) {
            if (p - min_seen > ans) {
                ans = p - min_seen;
            }
            if (p < min_seen) {
                min_seen = p;
            }
        }
        return ans;
    }
};
