//
// Created by David Silva on 28/08/24.
//

#include <iostream>
#include <ForwardList/ForwardList.h>


int main() {
    ForwardList<int> list;

    // Test: Verificar si la lista está vacía
    std::cout << "¿La lista está vacía? " << (list.empty() ? "Sí" : "No") << std::endl;

    // Test: Agregar elementos al frente y al final
    list.push_front(10);
    list.push_front(20);
    list.push_back(30);
    list.push_back(40);

    // Test: Verificar el tamaño de la lista
    std::cout << "Tamaño de la lista: " << list.size() << std::endl;

    // Test: Acceder a los elementos usando front() y back()
    std::cout << "Primer elemento (front): " << list.front() << std::endl;
    std::cout << "Último elemento (back): " << list.back() << std::endl;

    // Test: Acceder a elementos por índice
    std::cout << "Elemento en índice 0: " << list[0] << std::endl;
    std::cout << "Elemento en índice 1: " << list[1] << std::endl;
    std::cout << "Elemento en índice 2: " << list[2] << std::endl;
    std::cout << "Elemento en índice 3: " << list[3] << std::endl;

    // Test: Remover elementos del frente y del final
    std::cout << "Removiendo el primer elemento (pop_front): " << list.pop_front() << std::endl;
    std::cout << "Nuevo primer elemento: " << list.front() << std::endl;

    std::cout << "Removiendo el último elemento (pop_back): " << list.pop_back() << std::endl;
    std::cout << "Nuevo último elemento: " << list.back() << std::endl;

    // Test: Verificar el tamaño de la lista después de eliminar
    std::cout << "Tamaño de la lista después de eliminar: " << list.size() << std::endl;

    // Test: Invertir la lista
    list.reverse();
    std::cout << "Lista después de invertir: ";
    for (int i = 0; i < list.size(); i++) {
        std::cout << list[i] << " ";
    }
    std::cout << std::endl;

    // Test: Limpiar la lista
    list.clear();
    std::cout << "¿La lista está vacía después de limpiar? " << (list.empty() ? "Sí" : "No") << std::endl;
    std::cout << "Tamaño de la lista después de limpiar: " << list.size() << std::endl;

    return 0;
}