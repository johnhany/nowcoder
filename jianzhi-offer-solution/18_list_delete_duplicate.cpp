/*
    NOTE: Memory leak is not addressed.
*/

/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
        ListNode* dummy = new ListNode(-1);
        dummy->next = pHead;
        ListNode* cur = pHead;
        ListNode* prev = dummy;
        while (cur && cur->next) {
            if (cur->val == cur->next->val) {
                cur = cur->next;
                while (cur->next && cur->next->val == cur->val)
                    cur = cur->next;
                prev->next = cur->next;
                cur = cur->next;
            } else {
                prev = cur;
                cur = cur->next;
            }
        }
        return dummy->next;
    }
};