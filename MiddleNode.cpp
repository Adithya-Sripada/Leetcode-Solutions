struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* middleNode(ListNode* head) {
    if(!head || !head->next) return head;
    ListNode* n = head;
    ListNode* n2 = head;
    while(n && n->next) {
        n2 = n2->next;
        n = n->next->next;
    }
    return n2;
}
