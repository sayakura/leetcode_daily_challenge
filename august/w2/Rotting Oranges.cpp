class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> sources;
        const vector<pair<int, int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        int minutes = -1;
        int orange = 0;
        int height = grid.size();
        int width = grid[0].size(); 
        vector<vector<bool>> rotten(height, vector<bool>(width, false));
        
        for (int r = 0; r < height; r++) {
            for (int c = 0; c < width; c++) {
                if (grid[r][c] == 2)
                    sources.push({r, c});
                if (grid[r][c] != 0)
                    orange++;
            }
        }
        while (!sources.empty()) {
            int num = sources.size();
            while (num--) {
                auto cur = sources.front();
                sources.pop();
                orange--;
                for (auto d : directions) {
                    int newRow = cur.first + d.first;
                    int newCol = cur.second + d.second;
                    if (newRow < 0 || newRow >= height ||
                        newCol < 0 || newCol >= width)
                        continue ; 
                    if (grid[newRow][newCol] == 1 && !rotten[newRow][newCol]) {
                        rotten[newRow][newCol] = true;
                        sources.push({ newRow, newCol });
                    }
                }
            }
            minutes++;
        }
        if (orange > 0)
            return -1;
        return minutes < 0 ? 0 : minutes;
    }
};