class Solution {
public:
    int movingCount(int threshold, int rows, int cols)
    {
        int count = 0;
        vector<vector<bool>> flag(rows, vector<bool>(cols, false));
        check(threshold, rows, cols, 0, 0, count, flag);
        return count;
    }

    void check(int threshold, int rows, int cols,
              int x, int y, int& count, vector<vector<bool>>& flag) {
        if (x < 0 || x >= rows || y < 0 || y >= cols) return;
        if (valid(x, y, threshold) && !flag[x][y]) {
            ++count;
            flag[x][y] = true;
            check(threshold, rows, cols, x-1, y, count, flag);
            check(threshold, rows, cols, x+1, y, count, flag);
            check(threshold, rows, cols, x, y-1, count, flag);
            check(threshold, rows, cols, x, y+1, count, flag);
        }
    }

    bool valid(int x, int y, int threshold) {
        int sum = 0;
        while (x) {
            sum += x % 10;
            if (sum > threshold) return false;
            x = x / 10;
        }
        while (y) {
            sum += y % 10;
            if (sum > threshold) return false;
            y = y / 10;
        }
        return sum <= threshold ? true : false;
    }
};