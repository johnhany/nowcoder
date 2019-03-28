/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        bool rst = false;
        if (pRoot1 != nullptr && pRoot2 != nullptr) {
            rst = matchTree(pRoot1, pRoot2);
            if (!rst)
                rst = HasSubtree(pRoot1->left, pRoot2);
            if (!rst)
                rst = HasSubtree(pRoot1->right, pRoot2);
        }
        return rst;
    }
    
    bool matchTree(TreeNode* tree1, TreeNode* tree2) {
        if (tree2 == nullptr) return true;
        if (tree1 == nullptr) return false;
        if (tree1->val == tree2->val) {
            return matchTree(tree1->left, tree2->left) &&
                   matchTree(tree1->right, tree2->right);
        }
        return false;
    }
    
    bool equalDouble(double num1, double num2) {
        if (num1 - num2 > -0.000001 && num1 - num2 < 0.000001) return true;
        else return false;
    }
};