/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> forward;
        while (head) {
            forward.push_back(head->val);
            head = head->next;
        }
        vector<int> backward;
        for (int i = forward.size()-1; i >=0; --i)
            backward.emplace_back(std::move(forward[i]));
        return backward;
    }
};