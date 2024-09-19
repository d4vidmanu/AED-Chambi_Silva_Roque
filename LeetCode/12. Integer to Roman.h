#ifndef INC_12_INTEGER_TO_ROMAN_H
#define INC_12_INTEGER_TO_ROMAN_H
class Solution {
public:
    string intToRoman(int num) {
        unordered_map<int, string> romanMap = {
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"},
            {90, "XC"}, {50, "L"}, {40, "XL"}, {10, "X"}, {9, "IX"},
            {5, "V"}, {4, "IV"}, {1, "I"}
        };

        vector<int> keys = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

        string roman = "";

        for (int key : keys) {
            while (num >= key) {
                roman += romanMap[key];
                num -= key;
            }
        }

        return roman;
    }
};
#endif //INC_12_INTEGER_TO_ROMAN_H
