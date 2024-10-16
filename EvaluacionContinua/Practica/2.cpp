#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int contar_pares(vector<int>& nums, int K) {
    unordered_map<int, int> frecuencia;
    int contador = 0;

    // Recorremos el arreglo una sola vez
    for (int num : nums) {
        int complementario = K - num;

        // Si el complementario ya está en el mapa, se cuenta cuántas veces ha aparecido
        if (frecuencia.find(complementario) != frecuencia.end()) {
            contador += frecuencia[complementario];
        }

        // Incrementamos la frecuencia del número actual
        frecuencia[num]++;
    }

    return contador;
}

int main() {
    // Ejemplo 1
    vector<int> nums1 = {1, 2, 3, 4, 3};
    int K1 = 6;
    cout << "Numero de pares que suman " << K1 << ": " << contar_pares(nums1, K1) << endl;

    // Ejemplo 2
    vector<int> nums2 = {1, 5, 1, 5};
    int K2 = 6;
    cout << "Numero de pares que suman " << K2 << ": " << contar_pares(nums2, K2) << endl;

    return 0;
}