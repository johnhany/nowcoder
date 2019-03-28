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
    ListNode* ReverseList(ListNode* pHead) {
        if (pHead == nullptr) return nullptr;
        if (pHead->next == nullptr) return pHead;
        ListNode *pEnd = nullptr, *pCur = pHead, *pNext = pHead->next;
        do {
            pCur->next = pEnd;
            pEnd = pCur;
            pCur = pNext;
            pNext = pNext->next;
        } while (pNext);
        pCur->next = pEnd;
        return pCur;
    }
};