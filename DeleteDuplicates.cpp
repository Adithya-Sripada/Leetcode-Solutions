
struct ListNode {
   int val;
   ListNode *next;
   ListNode() : val(0), next(nullptr) {}
   ListNode(int x) : val(x), next(nullptr) {}
   ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* deleteDuplicates(ListNode* head) {
    ListNode* node = head;
    ListNode* temp;
    while(node) {
        if(node->next != nullptr && node->next->val == node->val) {
            temp = node->next;
            node->next = temp->next;
            delete temp;
            continue;
        }
        node = node->next;
    }
    return head;
}
