class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();

        if(image[sr][sc] == color)
            return image;

        queue<pair<int, int>> q;
        q.push({sr, sc});
        int orgClr = image[sr][sc];
        image[sr][sc] = color;

        int drow[] = {0, -1, 0, +1};
        int dcol[] = {-1, 0, +1, 0};
        int r, c, nrow, ncol;
        while(!q.empty()) {
            r = q.front().first;
            c = q.front().second;
            q.pop();

            for(int i = 0; i < 4; i++) {
                nrow = r + drow[i];
                ncol = c + dcol[i];

                if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && image[nrow][ncol] == orgClr) {
                    q.push({nrow, ncol});
                    image[nrow][ncol] = color;
                }
            }
        }

        return image;
    }
};