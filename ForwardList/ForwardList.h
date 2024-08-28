//
// Created by David Silva on 28/08/24.
//

#ifndef FORWARD_LIST_H
#define FORWARD_LIST_H

#include <stdexcept>  // Para las excepciones

// Definición de la clase template ForwardList
template <typename T>
class ForwardList {
private:
    struct Node {
        T data;
        Node* next;
        Node(T value) : data(value), next(nullptr) {}
    };

    Node* head;
    Node* tail;
    int listSize;

public:
    // Constructor y destructor
    ForwardList() : head(nullptr), tail(nullptr), listSize(0) {}
    ~ForwardList() { clear(); }

    // Funciones miembro
    T front() {
        if (head != nullptr) {
            return head->data;
        }
        throw std::runtime_error("La lista está vacía");
    }

    T back() {
        if (tail != nullptr) {
            return tail->data;
        }
        throw std::runtime_error("La lista está vacía");
    }

    void push_front(T value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
        listSize++;
    }

    void push_back(T value) {
        Node* newNode = new Node(value);
        if (tail == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        listSize++;
    }

    T pop_front() {
        if (head == nullptr) {
            throw std::runtime_error("La lista está vacía");
        }
        Node* temp = head;
        T data = temp->data;
        head = head->next;
        if (head == nullptr) {
            tail = nullptr;
        }
        delete temp;
        listSize--;
        return data;
    }

    T pop_back() {
        if (tail == nullptr) {
            throw std::runtime_error("La lista está vacía");
        }
        if (head == tail) {
            T data = tail->data;
            delete head;
            head = tail = nullptr;
            listSize--;
            return data;
        }
        Node* current = head;
        while (current->next != tail) {
            current = current->next;
        }
        T data = tail->data;
        delete tail;
        tail = current;
        tail->next = nullptr;
        listSize--;
        return data;
    }

    T operator[](int index) {
        if (index < 0 || index >= listSize) {
            throw std::out_of_range("Índice fuera de rango");
        }
        Node* current = head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        return current->data;
    }

    bool empty() {
        return head == nullptr;
    }

    int size() {
        return listSize;
    }

    void clear() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
        listSize = 0;
    }

    void reverse() {
        if (head == nullptr || head->next == nullptr) return;
        Node* prev = nullptr;
        Node* current = head;
        tail = head; // El antiguo head será el nuevo tail
        while (current != nullptr) {
            Node* next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }
};

#endif // FORWARD_LIST_H