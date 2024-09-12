class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode* current = head;

        while (current && current->next) {
            int gcdValue = gcd(current->val, current->next->val);

            ListNode* gcdNode = new ListNode(gcdValue);

            gcdNode->next = current->next;
            current->next = gcdNode;

            current = gcdNode->next;
        }

        return head;
    }

private:
    int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
};
