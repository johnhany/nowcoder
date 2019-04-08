class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        if (sequence.empty()) return false;
        return isTree(sequence, 0, sequence.size()-1);
    }

    bool isTree(vector<int>& nums, int left, int right) {
        if (left >= right) return true;
        int i = left;
        while (i < right && nums[i] < nums[right]) i++;
        int j = i;
        while (j < right && nums[j] > nums[right]) j++;
        if (j < right)
            return false;
        else
            return isTree(nums, left, i-1) && isTree(nums, i, right-1);
    }
};