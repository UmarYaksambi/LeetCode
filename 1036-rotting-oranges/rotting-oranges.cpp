class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int orgCnt = 0;

        queue<pair<pair<int, int>, int>> q;  // {{r, c}, t}

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                    orgCnt++;
                }
                else if(grid[i][j] == 1) {
                    orgCnt++;
                }
            }
        }

        int drow[] = {-1, 0, +1, 0};
        int dcol[] = {0, -1, 0,  +1};
        int row, col, tm, t = 0;
        while(!q.empty()) {
            row = q.front().first.first;
            col = q.front().first.second;
            tm = q.front().second;
            q.pop();

            orgCnt--;

            t = max(t, tm);

            for(int i = 0; i < 4; i++) {
                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && grid[nrow][ncol] == 1) {
                    q.push({{nrow, ncol}, t + 1});
                    grid[nrow][ncol] = 2;
                }
            }
        }

        return orgCnt == 0 ? t : -1;
    }
};