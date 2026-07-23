class Solution {
public:
    void dfs(int row, int col, vector<vector<int>>& image, int originalColor, int newColor) {

        // Base Case
        if (row < 0 || col < 0 ||
            row >= image.size() ||
            col >= image[0].size() ||
            image[row][col] != originalColor) {
            return;
        }

        // Change the color
        image[row][col] = newColor;

        // Visit all 4 directions
        dfs(row + 1, col, image, originalColor, newColor);
        dfs(row - 1, col, image, originalColor, newColor);
        dfs(row, col + 1, image, originalColor, newColor);
        dfs(row, col - 1, image, originalColor, newColor);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {

        int originalColor = image[sr][sc];

        // Prevent infinite recursion
        if (originalColor == color) {
            return image;
        }

        dfs(sr, sc, image, originalColor, color);

        return image;
    }
};