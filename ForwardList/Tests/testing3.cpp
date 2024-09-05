class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) {
            return head; // Si la lista está vacía o tiene solo un nodo
        }

        ListNode* odd = head; // Inicialmente el primer nodo es impar
        ListNode* even = head->next; // El segundo nodo es par
        ListNode* evenHead = even; // Guardar la cabeza de los pares para conectarlos luego

        // Recorre la lista mientras haya al menos un nodo par y uno impar
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