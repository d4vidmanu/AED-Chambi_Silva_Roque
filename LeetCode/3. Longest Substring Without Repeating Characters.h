//
// Created by David Silva on 18/09/24.
//

#ifndef INC_3_LONGEST_SUBSTRING_WITHOUT_REPEATING_CHARACTERS_H
#define INC_3_LONGEST_SUBSTRING_WITHOUT_REPEATING_CHARACTERS_H
class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        std::unordered_map<char, int> h;
        int maxLength = 0;
        int start = 0;

        for(int i = 0; i < s.size(); ++i){
            char currentChar = s[i];
            if(h.find(currentChar) != h.end()){
                h[currentChar]++;
            } else{
                h[currentChar] = 1;
            }

            while(h[currentChar] > 1){
                char startChar = s[start];
                h[startChar]--;
                if(h[startChar] == 0){
                    h.erase(startChar);
                }
                start++;
            }

            int currentLength = i - start + 1;
            if(currentLength > maxLength){
                maxLength = currentLength;
            }
        }

        return maxLength;
    }
};
#endif //INC_3_LONGEST_SUBSTRING_WITHOUT_REPEATING_CHARACTERS_H
