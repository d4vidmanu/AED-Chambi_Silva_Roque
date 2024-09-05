class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if (head == nullptr){
            return nullptr;
        }

        ListNode* lento = head;
        ListNode* rapido = head;

        while (rapido!= nullptr && rapido -> next != nullptr){
            lento = lento ->next;
            rapido = rapido -> next -> next;
        }

        return lento;

    }
};