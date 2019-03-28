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
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        if (pListHead == nullptr || k == 0) return nullptr;
        ListNode* behind = pListHead;
        int len = 0;
        while (pListHead) {
            pListHead = pListHead->next;
            if (len >= k-1) {
                if (pListHead != nullptr)
                    behind = behind->next;
                else
                    return behind;
            } else
                ++len;
        }
        return nullptr;
    }
};