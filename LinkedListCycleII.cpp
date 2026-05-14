#include <map>

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(nullptr) {}
 };

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == nullptr || head->next == nullptr) return nullptr;
        std::map<ListNode*, int> m;
        ListNode* node = head;
        while(node) {
            try {
                m.at(node);
                return node;
            }
            catch(const std::out_of_range& ex) {
                m.insert(std::pair<ListNode*, int>{node, 1});
            }
            node = node->next;
        }
        return nullptr;
    }
};
