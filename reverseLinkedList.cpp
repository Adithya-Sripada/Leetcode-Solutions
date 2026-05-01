struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
 public:
    ListNode* reverse(ListNode *head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode* last = nullptr;
        ListNode* second = head;
        ListNode* first = head->next;
        while (second) {
            second->next = last;
            last = second;
            second = first;
            if (first != nullptr) first = first->next;
        }
        return last;
    }
};