#include <queue>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* reverse(ListNode* head) {
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

    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k == 1) return head;
        ListNode* slow = head;
        std::queue<ListNode*> heads;
        ListNode* fast = head->next;
        int count = 0;
        while(head) {
            count++;
            if(count%k == 0 && count != 0) {
                head->next = nullptr;
                heads.push(reverse(slow));
                slow = fast;
                head = slow;
                fast = fast->next;
                continue;
            }
            if(fast != nullptr) fast = fast->next;
            head = head->next;
        }
        heads.push(slow);
        ListNode* newhead = heads.front();
        heads.pop();
        fast = newhead;
        while(!heads.empty()) {
            if(fast->next == nullptr) {
                fast->next = heads.front();
                heads.pop();
            }
            fast = fast->next;
        }
        return newhead;
    }
};