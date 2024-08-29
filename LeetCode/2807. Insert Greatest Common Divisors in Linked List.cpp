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
            // Calcular el GCD del nodo actual y el siguiente nodo
            int gcdValue = gcd(current->val, current->next->val);

            // Crear un nuevo nodo con el valor GCD
            ListNode* gcdNode = new ListNode(gcdValue);

            // Insertar el nodo GCD entre el nodo actual y el siguiente nodo
            gcdNode->next = current->next;
            current->next = gcdNode;

            // Moverse al nodo después del nuevo nodo GCD insertado
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
