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