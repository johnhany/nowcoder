/*
struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
        
    }
};
*/
class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode) {
        if (pNode == nullptr) return nullptr;
        if (pNode->right) {
            pNode = pNode->right;
            while (pNode->left) {
                pNode = pNode->left;
            }
            return pNode;
        } else if (pNode->next) {
            TreeLinkNode* parent = pNode->next;
            while (parent && parent->right == pNode) {
                pNode = parent;
                parent = parent->next;
            }
            return parent;
        }
        return nullptr;
    }
};