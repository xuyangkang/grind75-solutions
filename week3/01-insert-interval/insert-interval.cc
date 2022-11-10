class Solution {
private:
    tuple<bool, int, int> try_merge(int l1, int r1, int l2, int r2) {
        int l = min(l1, l2);
        int r = max(r1, r2);
        bool overlap = r1 - l1 + r2 - l2 >= r - l;
        return {overlap, l, r};
    }
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int l = newInterval[0];
        int r = newInterval[1];
        for (const auto &i : intervals) {
            auto [overlap, new_l, new_r] = try_merge(i[0], i[1], l, r);
            if (overlap) {
                l = new_l;
                r = new_r;
            } else {
                ans.push_back(i);
            }
        }
        ans.push_back({l, r});
        for (int i = ans.size() - 1; i > 0; i--) {
            if (ans[i - 1][0] > ans[i][0]) {
                swap(ans[i - 1], ans[i]);
            }
        }
        return ans;
    }
};