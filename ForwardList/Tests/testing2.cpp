class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if (head == nullptr) {
            return nullptr;
        }

        ListNode* slow = head; // Puntero lento
        ListNode* fast = head; // Puntero rápido

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next; // Avanza el puntero lento
            fast = fast->next->next; // Avanza el puntero rápido
        }

        return slow;
    }
};