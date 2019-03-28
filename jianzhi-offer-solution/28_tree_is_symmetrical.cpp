/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    bool isSymmetrical(TreeNode* pRoot)
    {
        return compareMirror(pRoot, pRoot);
    }

    bool compareMirror(TreeNode* tree1, TreeNode* tree2) {
        if (tree1 == nullptr && tree2 == nullptr) return true;
        if (tree1 != nullptr && tree2 != nullptr && tree1->val == tree2->val) {
            return compareMirror(tree1->left, tree2->right) &&
                   compareMirror(tree1->right, tree2->left);
        }
        return false;
    }
};