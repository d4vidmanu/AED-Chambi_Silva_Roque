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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if (!head || !head->next) return head;  // No pairs to process if list is empty or has one element

        ListNode* current = head;

        while (current && current->next) {
            // Calculate GCD of the current node and the next node
            int gcdValue = gcd(current->val, current->next->val);

            // Create a new node with the GCD value
            ListNode* gcdNode = new ListNode(gcdValue);

            // Insert the GCD node between current node and next node
            gcdNode->next = current->next;
            current->next = gcdNode;

            // Move to the node after the newly inserted GCD node
            current = gcdNode->next;
        }

        return head;
    }
};