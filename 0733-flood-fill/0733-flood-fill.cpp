class Solution {
public:
    void dfsFloodFill(vector<vector<int>>& image, int m, int n, int sr, int sc, int color, int cur) {
    if (sr < 0 || sc < 0 || sr >= m || sc >= n) return;
    if (image[sr][sc] != cur) return;
    image[sr][sc] = color;

    int dx[] = { 1, -1, 0, 0 };
    int dy[] = { 0, 0, 1, -1 };

    for (int i = 0; i < 4; i++)
        dfsFloodFill(image, m, n, sr + dx[i], sc + dy[i], color, cur);
}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    int cur = image[sr][sc];
    int m = image.size(), n = image[0].size();

    if (cur != color)
        dfsFloodFill(image, m, n, sr, sc, color, cur);

    return image;
}
};