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
    ListNode* swapPairs(ListNode* head) {
        // Handle base cases where no swapping is needed
        if (!head || !head->next) return head;

        // Initialize pointers
        ListNode* newHead = head->next;  // The new head will be the second node after swapping
        ListNode* prev = nullptr;
        ListNode* current = head;

        while (current && current->next) {
            // Identify the two nodes to swap
            ListNode* first = current;
            ListNode* second = current->next;

            // Perform the swap
            first->next = second->next;
            second->next = first;

            // Connect the previous pair with the current pair
            if (prev) {
                prev->next = second;
            }

            // Move pointers forward for the next pair
            prev = first;
            current = first->next;
        }

        return newHead;
    }
};