class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        if (array.empty() || array[0].empty()) return false;
        if (target < array[0][0]) return false;
        int i = 0, j = array[0].size() - 1;
        while (i < array.size() || j >= 0) {
            if (array[i].empty()) return false;
            if (array[i][j] == target) return true;
            else if (array[i][j] > target) --j;
            else ++i;
        }
        return false;
    }
};