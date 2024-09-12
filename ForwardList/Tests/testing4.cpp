class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto comp = [](ListNode* a, ListNode* b) { return a->val > b->val; };
        priority_queue<ListNode*, vector<ListNode*>, decltype(comp)> pq(comp);

        for (ListNode* list : lists) {
            if (list) {
                pq.push(list);
            }
        }

        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (!pq.empty()) {
            ListNode* minNode = pq.top();
            pq.pop();

            tail->next = minNode; // Añadir el nodo mínimo a la lista resultante
            tail = tail->next;

            if (minNode->next) {
                pq.push(minNode->next); // Insertar el siguiente nodo de la lista
            }
        }

        return dummy.next;
    }
};