class Solution {
    vector<int> dirs = {-1, 0, 1, 0, -1};
    int colorSrc;
    int colorDst;
    void fill(vector<vector<int>>& image, int i, int j, vector<vector<bool>>& vis) {
        image[i][j] = colorDst;
        vis[i][j] = true;
        for (int k = 0; k < 4; k++) {
            int ni = i + dirs[k], nj = j + dirs[k + 1];
            if (ni < 0 || nj < 0 || ni >= image.size() || nj >= image[0].size() || image[ni][nj] != colorSrc || vis[ni][nj]) continue;
            fill(image, ni, nj, vis);
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        colorSrc = image[sr][sc];
        colorDst = color;
        vector<vector<bool>> vis(image.size(), vector<bool>(image[0].size(), false));
        fill(image, sr, sc, vis);
        return image;
    }
};