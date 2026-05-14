#include <string>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class MyLinkedList {
private:
    ListNode* head;
    int size;
public:
    MyLinkedList() {
        head = nullptr;
        size = 0;
    }

    int get(int index) {
        if(index >= size) return -1;
        ListNode* node = head;
        int c = 0;
        while(node) {
            if(c == index) {
                return node->val;
            }
            node = node->next;
            c++;
        }
        return -1;
    }

    void addAtHead(int val) {
        ListNode* n = new ListNode(val);
        if(size == 0) {
            head = n;
            size++;
            return;
        }
        n->next = head;
        head = n;
        size++;
    }

    void addAtTail(int val) {
        ListNode* n = new ListNode(val);
        if(size == 0){
            head = n;
            size++;
            return;
        }
        ListNode* node = head;
        while(node->next){
            node = node->next;
        }
        node->next = n;
        size++;
    }

    void addAtIndex(int index, int val) {
        if(index > size) return;
        ListNode* n = new ListNode(val);
        if(size == 0) {
            head = n;
        }
        else if(index == 0) {
            addAtHead(val);
        }
        else if(index == size) addAtTail(val);
        else {
            int c = 0;
            ListNode* prev = head;
            while(c != index-1) {
                prev = prev->next;
                c++;
            }
            n->next = prev->next;
            prev->next = n;
        }
        size++;
    }

    void deleteAtIndex(int index) {
        if(index >= size) return;
        ListNode* temp;
        if(size == 1) {
            delete head;
            head = nullptr;
        }
        else if(index == 0) {
            temp = head;
            head = head->next;
            delete temp;
            temp = nullptr;
        }
        else {
            int c = 0;
            ListNode* prev = head;
            while(c != index-1) {
                prev = prev->next;
                c++;
            }
            temp = prev->next;
            if(index == size-1) {
                prev->next = nullptr;
                delete temp;
                temp = nullptr;
                size--;
                return;
            }

            prev->next = temp->next;
            delete temp;
            temp = nullptr;
        }
        size--;
    }
};