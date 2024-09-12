class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* secondary = new ListNode(0, head);
        ListNode* current = secondary;

        while (current->next != nullptr) {
            if (current->next->val == val) {
                ListNode* temp = current->next;
                current->next = current->next->next;
                delete temp;
            } else {
                current = current->next;
            }
        }

        ListNode* newHead = secondary->next;
        delete secondary;
        return newHead;
    }
};