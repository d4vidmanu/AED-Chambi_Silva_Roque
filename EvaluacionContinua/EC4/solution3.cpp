//
// Created by LUIS FERNANDO on 12/09/2024.
//

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total_tank = 0, curr_tank = 0, start_station = 0;

        for(int i = 0; i < gas.size(); ++i){
            total_tank += gas[i] - cost[i];
            curr_tank += gas[i] - cost[i];

            if(curr_tank<0){
                start_station=i+1;
                curr_tank = 0;
            }
        }

        return total_tank >= 0 ? start_station:-1;
    }
};