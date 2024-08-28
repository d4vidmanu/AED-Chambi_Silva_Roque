#include "ForwardList.h"

// Implementación del constructor
template <typename T>
ForwardList<T>::ForwardList() : head(nullptr), tail(nullptr), listSize(0) {}

// Implementación del destructor
template <typename T>
ForwardList<T>::~ForwardList() {
    clear(); // Llama a clear para liberar memoria
}

// Aquí se implementarán las funciones miembro declaradas en el archivo de cabecera