/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* Merge(ListNode* l1, ListNode* l2)
    {
        if (!l1 && !l2)
            return nullptr;
        else if (!l1)
            return l2;
        else if (!l2)
            return l1;
        else {
            if (l1->val > l2->val)
                swap(l1, l2);
            ListNode *head = l1;
            while (l1->next && l2) {
                while (l2->val < l1->next->val) {
                    swap(l1->next, l2->next);
                    swap(l1->next, l2);
                }
                l1 = l1->next;
            }
            if (l2)
                l1->next = l2;
            return head;
        }
    }
};