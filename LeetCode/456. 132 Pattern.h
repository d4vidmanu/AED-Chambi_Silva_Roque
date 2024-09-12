#ifndef INC_456_132_PATTERN_H
#define INC_456_132_PATTERN_H


#include <iostream>
#include <climits>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return false;

        int third = INT_MIN;  // El valor que correspondería al número 2 en el patrón 132
        stack<int> st;

        for (int i = n - 1; i >= 0; --i) {
            if (nums[i] < third) {
                return true;  // Encontramos el patrón
            }
            while (!st.empty() && nums[i] > st.top()) {
                third = st.top();  // El nuevo valor para el "2" del patrón
                st.pop();
            }
            st.push(nums[i]);
        }
        return false;
    }
};

/*#include "LeetCode/456. 132 Pattern.h"

int main() {
    Solution sol;

    // Case 1: [1,2,3,4]
    vector<int> nums1 = {1, 2, 3, 4};
    cout << "Case 1: " << (sol.find132pattern(nums1) ? "True" : "False") << endl;  // Should return False

    // Case 2: [3,1,4,2]
    vector<int> nums2 = {3, 1, 4, 2};
    cout << "Case 2: " << (sol.find132pattern(nums2) ? "True" : "False") << endl;  // Should return True

    // Case 3: [-1,3,2,0]
    vector<int> nums3 = {-1, 3, 2, 0};
    cout << "Case 3: " << (sol.find132pattern(nums3) ? "True" : "False") << endl;  // Should return True

    return 0;
}*/


#endif //INC_456_132_PATTERN_H
