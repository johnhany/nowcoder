/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        if (pre.empty() || pre.size() != vin.size()) return nullptr;
        return recurseBT(pre, 0, pre.size()-1, vin, 0, vin.size()-1);
    }

    TreeNode* recurseBT(vector<int>& pre, int pre_s, int pre_e,
                        vector<int>& vin, int vin_s, int vin_e) {
        TreeNode* root = new TreeNode(pre[pre_s]);
        int pivot;
        for (int i = vin_s; i <= vin_e; ++i) {
            if (vin[i] == pre[pre_s]) {
                pivot = i;
                break;
            }
        }
        if (pivot > vin_s)
            root->left = recurseBT(pre, pre_s+1, pre_s+pivot-vin_s,
                                   vin, vin_s, pivot-1);
        if (vin_e > pivot)
            root->right = recurseBT(pre, pre_s+pivot-vin_s+1, pre_e,
                                    vin, pivot+1, vin_e);
        return root;
    }
};