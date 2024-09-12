#ifndef INC_347_TOP_K_FREQUENT_ELEMENTS_H
#define INC_347_TOP_K_FREQUENT_ELEMENTS_H

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freqMap;
        for (int num : nums) {
            freqMap[num]++;  // Contamos la frecuencia de cada número
        }

        // Usamos un min heap para los k elementos más frecuentes
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

        for (auto& [num, freq] : freqMap) {
            minHeap.push({freq, num});
            if (minHeap.size() > k) {
                minHeap.pop();  // Mantenemos solo los k más frecuentes
            }
        }

        vector<int> result;
        while (!minHeap.empty()) {
            result.push_back(minHeap.top().second);
            minHeap.pop();
        }

        return result;
    }
};

/*#include "LeetCode/347. Top K Frequent Elements.h"

int main() {
    Solution sol;

    // Case 1: nums = [1,1,1,2,2,3], k = 2
    vector<int> nums1 = {1, 1, 1, 2, 2, 3};
    int k1 = 2;
    vector<int> result1 = sol.topKFrequent(nums1, k1);
    cout << "Case 1: ";
    for (int r : result1) cout << r << " ";
    cout << endl;  // Expected output: [1, 2]

    return 0;
}*/

#endif //INC_347_TOP_K_FREQUENT_ELEMENTS_H
