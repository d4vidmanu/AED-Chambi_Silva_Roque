#include<vector>
using namespace std;
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total_gas = 0;
        int current_gas = 0;
        int start_index = 0;

        for (int i = 0; i < gas.size(); ++i) {
            total_gas += gas[i] - cost[i];
            current_gas += gas[i] - cost[i];

            if (current_gas < 0) {
                start_index = i + 1;
                current_gas = 0;
            }
        }

        if (total_gas >= 0) {
            return start_index;
        } else {
            return -1;
        }
    }
};
