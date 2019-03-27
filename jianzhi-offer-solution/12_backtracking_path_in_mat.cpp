class Solution {
public:
    bool hasPath(char* matrix, int rows, int cols, char* str)
    {
        if (matrix == nullptr || str == nullptr || rows == 0 || cols == 0)
            return false;
        vector<vector<bool>> flag(rows, vector<bool>(cols, false));
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (findPath(matrix, rows, cols, str,
                             flag, i, j))
                    return true;
            }
        }
        return false;
    }

    bool findPath(char* matrix, int rows, int cols, char* str,
                  vector<vector<bool>>& flag, int x, int y) {
        bool found = false;
        if (matrix[x*cols+y] == *str && !flag[x][y]) {
            flag[x][y] = true;
            if (*(str+1) == '\0') return true;
            if ((x > 0 && findPath(matrix, rows, cols, str+1, flag, x-1, y)) ||
                (x < rows-1 && findPath(matrix, rows, cols, str+1, flag, x+1, y)) ||
                (y > 0 && findPath(matrix, rows, cols, str+1, flag, x, y-1)) ||
                (y < cols-1 && findPath(matrix, rows, cols, str+1, flag, x, y+1)))
                found = true;
            if (!found) {
                flag[x][y] = false;
            }
        }
        return found;
    }
};