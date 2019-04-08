class Solution {
public:
    bool IsPopOrder(vector<int> pushV, vector<int> popV) {
        if (popV.size() != pushV.size()) return false;
        if (popV.empty()) return true;
        vector<int> stack;
        for (int i = 0, j = 0; j < popV.size();) {
            stack.push_back(pushV[i++]);
            while (j < popV.size() && stack.back() == popV[j]) {
                stack.pop_back();
                j++;
            }
        }
        return stack.empty();
    }
};