class Solution {
public:
    int numComponents(ListNode* head, vector<int>& M) {
        std::unordered_set<int> setM(M.begin(), M.end());
        int components = 0;
        ListNode* curr = head;

        while (curr != nullptr){
            if (setM.count(curr -> val) && (curr -> next == nullptr || !setM.count(curr->next->val))){
                components++;
            }
            curr = curr -> next;
        }

        return components;
    }
};