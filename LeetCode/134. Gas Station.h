#ifndef INC_134_GAS_STATION_H
#define INC_134_GAS_STATION_H

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total_tank = 0, curr_tank = 0, start_station = 0;

        for (int i = 0; i < gas.size(); ++i) {
            total_tank += gas[i] - cost[i];
            curr_tank += gas[i] - cost[i];

            if (curr_tank < 0) {
                start_station = i + 1;
                curr_tank = 0;  // Reiniciamos el tanque actual para empezar desde una nueva estación
            }
        }

        return total_tank >= 0 ? start_station : -1;
    }
};

/*#include "LeetCode/134. Gas Station.h"

int main() {
    Solution sol;

    // Case 1: gas = [1,2,3,4,5], cost = [3,4,5,1,2]
    vector<int> gas1 = {1, 2, 3, 4, 5};
    vector<int> cost1 = {3, 4, 5, 1, 2};
    cout << "Case 1: Start station: " << sol.canCompleteCircuit(gas1, cost1) << endl;  // Should return 3

    // Case 2: gas = [2,3,4], cost = [3,4,3]
    vector<int> gas2 = {2, 3, 4};
    vector<int> cost2 = {3, 4, 3};
    cout << "Case 2: Start station: " << sol.canCompleteCircuit(gas2, cost2) << endl;  // Should return -1

    return 0;
}*/


#endif //INC_134_GAS_STATION_H
