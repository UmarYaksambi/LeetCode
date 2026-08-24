class Solution {
private:
    int dp(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& memo) {
        if(i == 0 && j == 0)
            return grid[i][j];

        if(i < 0 || j < 0)
            return INT_MAX;

        if(memo[i][j] != -1)
            return memo[i][j];

        int left = dp(i - 1, j, grid, memo);
        int up = dp(i, j - 1, grid, memo);

        long minSum = min(left, up) + grid[i][j];

        return memo[i][j] = minSum;
    }

public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> memo(grid.size(), vector<int>(grid[0].size(), -1));

        return dp(grid.size()-1, grid[0].size()-1, grid, memo);
    }
};