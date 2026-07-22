struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* addTwoNumbers (ListNode* l1, ListNode* l2) {
    string n1="";
    string n2 = "";
    ListNode* head = new ListNode();
    while(l1 || l2) {
        if (l1) {
            n1 = to_string(l1->val) + n1;
            l1 = l1->next;
        }
        if (l2) {
            n2 = to_string(l2->val) + n2;
            l2 = l2->next;
        }
    }
    unsigned long long num1 = stoll(n1);
    unsigned long long num2 = stoll(n2);
    unsigned long long num = num1 + num2;
    string a = to_string(num);
    ListNode* temp;
    for (int i = 0; i < a.size(); i++) {
        int c = a[i] - 48;
        temp = new ListNode(c);
        temp->next = head->next;
        head->next = temp;
    }
    return head->next;
}
