#ifndef INC_739_DAILY_TEMPERATURES_H
#define INC_739_DAILY_TEMPERATURES_H

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> result(n, 0);  // Vector para almacenar los días de espera
        stack<int> st;

        for (int i = 0; i < n; ++i) {
            while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
                int prevIndex = st.top();
                st.pop();
                result[prevIndex] = i - prevIndex;  // Calculamos los días de espera
            }
            st.push(i);  // Guardamos el índice actual en la pila
        }

        return result;
    }
};

/*#include "LeetCode/Daily Temperatures.h"

int main() {
    Solution sol;

    // Case 1: temperatures = [73, 74, 75, 71, 69, 72, 76, 73]
    vector<int> temps1 = {73, 74, 75, 71, 69, 72, 76, 73};
    vector<int> result1 = sol.dailyTemperatures(temps1);
    cout << "Case 1: ";
    for (int r : result1) cout << r << " ";
    cout << endl;  // Expected output: [1, 1, 4, 2, 1, 1, 0, 0]

    return 0;
}*/


#endif //INC_739_DAILY_TEMPERATURES_H
