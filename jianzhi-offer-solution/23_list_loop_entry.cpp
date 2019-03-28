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
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        if (pHead == nullptr) return nullptr;
        std::set<ListNode*, ptr_less> hash;
        hash.emplace(pHead);
        while (pHead->next) {
            auto rst = hash.emplace(pHead->next);
            if (!rst.second)
                return pHead->next;
            pHead = pHead->next;
        }
        return nullptr;
    }

    struct ptr_less {
        bool operator()(ListNode* lhs, ListNode* rhs) {
            return lhs->val < rhs->val;
        }
    };
};