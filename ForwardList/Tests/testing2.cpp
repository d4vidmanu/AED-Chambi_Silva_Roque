class Solution {
public:
    // Función que devuelve el nodo del medio de la lista
    ListNode* middleNode(ListNode* head) {
        // Si la lista está vacía, devolver nullptr
        if (head == nullptr) {
            return nullptr;
        }

        // Inicializar dos punteros
        ListNode* slow = head; // Puntero lento
        ListNode* fast = head; // Puntero rápido

        // Mientras fast no llegue al final o sea el último nodo
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next; // Avanza el puntero lento
            fast = fast->next->next; // Avanza el puntero rápido
        }

        // Cuando el ciclo termina, slow apunta al nodo del medio
        return slow;
    }
};