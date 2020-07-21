// https://leetcode.com/explore/challenge/card/july-leetcoding-challenge/544/week-1-july-1st-july-7th/3383/

class Solution {
public:
    vector<pair<int, int>> directions = { {-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    int islandPerimeter(vector<vector<int>>& grid) {
        vector<vector<int>> map(grid.size(), vector<int>(grid[0].size(), 0));
        int n = grid.size(), m = grid[0].size();
        int sum = 0;
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < m; c++) {
                if (grid[r][c] == 0)
                    continue ;
                map[r][c] = 4;
                for (auto &d: directions) {
                    int nr = r + d.first;
                    int nc = c + d.second;
                    if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] != 0) 
                        map[r][c]--;
                }
                sum += map[r][c];
            }
        }
        return sum;
    }
};