class Solution {
public:
    // Función que descomprime la lista con codificación de longitud de ejecución
    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int> result; // Lista descomprimida final

        // Iteramos en pasos de 2 (i representa el índice del par [freq, val])
        for (int i = 0; i < nums.size(); i += 2) {
            int freq = nums[i]; // Frecuencia (cuántas veces aparece el valor)
            int val = nums[i + 1]; // Valor que se repite

            // Agregar `freq` veces el valor `val` al resultado
            for (int j = 0; j < freq; ++j) {
                result.push_back(val);
            }
        }

        return result; // Devolver la lista descomprimida
    }
};