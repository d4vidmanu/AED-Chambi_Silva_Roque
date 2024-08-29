class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode* newHead = head->next;
        ListNode* prev = nullptr;
        ListNode* current = head;

        while (current && current->next) {
            ListNode* first = current;
            ListNode* second = current->next;

            first->next = second->next;
            second->next = first;

            if (prev) {
                prev->next = second;
            }

            prev = first;
            current = first->next;
        }

        return newHead;
    }
};