class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        list<int> rst;
        if (matrix.empty() || matrix[0].empty()) return vector<int>{};
        int i = 0, j = 0, rows = matrix.size(), cols = matrix[0].size();
        int up = 0, bottom = rows-1, left = 0, right = cols-1;
        bool goRight = true, goDown = true;
        while (true) {
            bool drawAnything = false;
            if (up <= bottom && left <= right) {
                if (goRight) {
                    for (int y = left; y <= right; ++y) {
                        rst.push_back(matrix[up][y]);
                    }
                    ++up;
                } else {
                    for (int y = right; y >= left; --y) {
                        rst.push_back(matrix[bottom][y]);
                    }
                    --bottom;
                }
                goRight = !goRight;
                drawAnything = true;
            }
            if (up < bottom && left <= right) {
                if (goDown) {
                    for (int x = up; x <= bottom; ++x) {
                        rst.push_back(matrix[x][right]);
                    }
                    --right;
                } else {
                    for (int x = bottom; x >= up; --x) {
                        rst.push_back(matrix[x][left]);
                    }
                    ++left;
                }
                goDown = !goDown;
                drawAnything = true;
            }
            if (!drawAnything)
                break;
        }
        return vector<int>{std::make_move_iterator(std::begin(rst)),
                           std::make_move_iterator(std::end(rst))};
    }
};