#ifndef FORWARD_LIST_H
#define FORWARD_LIST_H

// Definición de la clase template ForwardList
template <typename T>
class ForwardList {
private:
    // Estructura interna para el nodo de la lista
    struct Node {
        T data;         // Datos almacenados en el nodo
        Node* next;     // Puntero al siguiente nodo

        Node(T value) : data(value), next(nullptr) {} // Constructor del nodo
    };

    Node* head;   // Puntero al primer nodo de la lista
    Node* tail;   // Puntero al último nodo de la lista
    int listSize; // Tamaño de la lista

public:
    // Constructor y destructor
    ForwardList();
    ~ForwardList();

    // Declaración de funciones miembro
    T front();                // Retorna el primer elemento
    T back();                 // Retorna el último elemento
    void push_front(T value); // Agrega un elemento al inicio
    void push_back(T value);  // Agrega un elemento al final
    T pop_front();            // Remueve el primer elemento
    T pop_back();             // Remueve el último elemento
    T operator[](int index);  // Retorna el elemento en la posición indicada
    bool empty();             // Retorna si la lista está vacía
    int size();               // Retorna el tamaño de la lista
    void clear();             // Elimina todos los elementos
    void sort();              // Ordena la lista
    void reverse();           // Revierte la lista
};

#include "ForwardList.cpp"

#endif