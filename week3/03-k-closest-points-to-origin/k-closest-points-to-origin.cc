double dist(const vector<int> &p) {
    return sqrt(p[0] * p[0] + p[1] * p[1]);
}
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        sort(points.begin(), points.end(), [](const auto &a, const auto &b) { return dist(a) < dist(b); });
        points.resize(k);
        return points;
    }
};