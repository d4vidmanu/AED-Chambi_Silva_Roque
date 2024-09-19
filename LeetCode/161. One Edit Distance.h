//
// Created by David Silva on 18/09/24.
//

#ifndef INC_161_ONE_EDIT_DISTANCE_H
#define INC_161_ONE_EDIT_DISTANCE_H
class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int lenS = s.size();
        int lenT = t.size();

        if (abs(lenS - lenT) > 1) return false;

        if (lenS < lenT) {
            swap(s, t);
            swap(lenS, lenT);
        }

        int i = 0, j = 0;
        bool foundDifference = false;

        while (i < lenS && j < lenT) {
            if (s[i] != t[j]) {
                if (foundDifference) {
                    // Si ya encontramos una diferencia, entonces retornamos falso
                    return false;
                }
                foundDifference = true;

                if (lenS != lenT) {
                    // Si las longitudes son diferentes, movemos solo el puntero del más largo
                    i++;
                    continue;
                }
            }
            // Si los caracteres son iguales o las longitudes son iguales, avanzamos ambos punteros
            i++;
            j++;
        }

        // Si no se ha encontrado ninguna diferencia pero hay un carácter extra en `s`
        return foundDifference || lenS != lenT;
    }
};
#endif //INC_161_ONE_EDIT_DISTANCE_H
