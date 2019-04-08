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
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        deque<TreeNode*> dq;
        if (root != nullptr)
            dq.push_back(root);
        vector<int> rst;
        while(!dq.empty()) {
            rst.push_back(dq.front()->val);
            if (dq.front()->left != nullptr)
                dq.push_back(dq.front()->left);
            if (dq.front()->right != nullptr)
                dq.push_back(dq.front()->right);
            dq.pop_front();
        }
        return rst;
    }
};