//
// Created by david on 12/09/2024.
//

#ifndef INC_946_VALIDATE_STACK_SEQUENCES_H
#define INC_946_VALIDATE_STACK_SEQUENCES_H

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int j = 0;  // Apunta al índice de "popped"

        for (int i = 0; i < pushed.size(); ++i) {
            st.push(pushed[i]);  // Empujamos los elementos de "pushed" a la pila

            // Si el tope de la pila es igual al elemento actual de "popped", seguimos sacando de la pila
            while (!st.empty() && st.top() == popped[j]) {
                st.pop();
                j++;
            }
        }

        // Si la pila se vació, es que la secuencia es válida
        return st.empty();
    }
};

/*#include "LeetCode/946. Validate Stack Sequences.h"

int main() {
    Solution sol;

    // Case 1: pushed = [1,2,3,4,5], popped = [4,5,3,2,1]
    vector<int> pushed1 = {1, 2, 3, 4, 5};
    vector<int> popped1 = {4, 5, 3, 2, 1};
    cout << "Case 1: " << (sol.validateStackSequences(pushed1, popped1) ? "True" : "False") << endl;  // Should return True

    // Case 2: pushed = [1,2,3,4,5], popped = [4,3,5,1,2]
    vector<int> pushed2 = {1, 2, 3, 4, 5};
    vector<int> popped2 = {4, 3, 5, 1, 2};
    cout << "Case 2: " << (sol.validateStackSequences(pushed2, popped2) ? "True" : "False") << endl;  // Should return False

    return 0;
}*/

#endif //INC_946_VALIDATE_STACK_SEQUENCES_H
