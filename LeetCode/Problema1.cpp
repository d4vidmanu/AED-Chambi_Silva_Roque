#include <iostream>
#include <vector>

using namespace std;

int contar_pares(vector<int>& nums, int K) {
    int contador = 0;
    int n = nums.size();

    // Recorremos el arreglo con dos bucles
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) { // j siempre es mayor que i
            if (nums[i] + nums[j] == K) {
                contador++;
            }
        }
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