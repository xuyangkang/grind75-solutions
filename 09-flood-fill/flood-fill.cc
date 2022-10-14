const int TODO = -1;
const vector<vector<int>> DIRECTIONS = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
class Solution {
private:
    void dfs(vector<vector<int>>& image, const int sr, const int sc, const int old_color) {
        image[sr][sc] = TODO;

        for (const auto &d : DIRECTIONS) {
            int new_sr = sr + d[0];
            int new_sc = sc + d[1];
            if (new_sr >= 0 && new_sr < image.size() && new_sc >= 0 && new_sc < image[0].size()
                && image[new_sr][new_sc] == old_color) {
                dfs(image, new_sr, new_sc, old_color);
            }
        }
    }


public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>> image_copy = image;
        int old_color = image[sr][sc];
        dfs(image_copy, sr, sc, old_color);
        for (auto &v : image_copy) {
            for (auto &e : v) {
                if (e == TODO) {
                    e = color;
                }
            }
        }
        return image_copy;
    }
};
