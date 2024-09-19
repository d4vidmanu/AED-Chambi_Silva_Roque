#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> h;
        h['I'] = 1;
        h['V'] = 5;
        h['X'] = 10;
        h['L'] = 50;
        h['C'] = 100;
        h['D'] = 500;
        h['M'] = 1000;
        
        int sum = 0;
        for(int i = 0; i < s.size(); ++i){
            if(i+1 < s.size() && h[s[i]] < h[s[i+1]]){
                sum += h[s[i+1]] - h[s[i]];
                ++i;
            } else {
                sum += h[s[i]];
            }
        }
        return sum;
    }
};