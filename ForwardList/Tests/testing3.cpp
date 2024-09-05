class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }

        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenHead = even;

        while (even && even->next) {
            odd->next = even->next; // Conectar el siguiente nodo impar
            odd = odd->next; // Mover el puntero impar
            even->next = odd->next; // Conectar el siguiente nodo par
            even = even->next; // Mover el puntero par
        }

        odd->next = evenHead; // Conectar el último nodo impar con el primero par
        return head;
    }
};