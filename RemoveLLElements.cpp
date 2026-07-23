/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
ListNode* removeElements(ListNode* head, int val) {
    if(!head) return nullptr;

    ListNode* temp;
    if(head->val == val) {
        temp = head->next;
        delete head;
        head = temp;
    }
    ListNode* node = head;
    for(node; node->next != nullptr; node = node->next) {
        if(node->next->next == nullptr  && node->next->val == val) {
            temp = node->next;
            delete temp;
            node->next = nullptr;
            break;
        }
        else if(node->next->val == val) {
            temp = node->next;
            node->next = temp->next;
            delete temp;
        }
    }
    return head;
}
};
