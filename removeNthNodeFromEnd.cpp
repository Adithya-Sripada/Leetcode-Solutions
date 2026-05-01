struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head->next == nullptr) {
            delete head;
            head = nullptr;
            return head;
        }

        ListNode* temp = head;
        ListNode* node = head;
        int size = 0;
        for(node; node != nullptr; node = node->next){
            size++;
        }
        n = size-n;
        if(n == 0){
            head = head->next;
            delete temp;
            temp = nullptr;
            return head;
        }
        node = head;
        for(int i = 0; i < size; i++){
            if(i == n-1) break;
            node = node->next;
        }
        temp = node->next;
        if(temp == nullptr) {
            delete node;
            return head;
        }
        node->next = temp->next;
        temp->next = nullptr;
        delete temp;
        temp = nullptr;
        return head;
    }
};