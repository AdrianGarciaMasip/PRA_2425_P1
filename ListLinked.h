#ifndef LISTLINKED_H
#define LISTLINKED_H

#include <iostream>
#include "List.h"
#include "Node.h"

using namespace std;

template <typename T>
class ListLinked : public List<T> {
private:
    Node<T>* first; // Puntero al primer nodo de la lista
    int n;          // Número de elementos en la lista

public:
    // Constructor
    ListLinked() : first(nullptr), n(0) {}

    // Destructor
    ~ListLinked() {
        while (first != nullptr) {
            Node<T>* temp = first;
            first = first->getNext();
            delete temp;
        }
    }

    // Insertar un elemento en una posición
    void insert(int pos, T e) override {
        if (pos < 0 || pos > n) {
            throw out_of_range("Posición inválida");
        }

        if (pos == 0) {
            first = new Node<T>(e, first);
        } else {
            Node<T>* prev = first;
            for (int i = 0; i < pos - 1; i++) {
                prev = prev->getNext();
            }
            prev->setNext(new Node<T>(e, prev->getNext()));
        }

        n++;
    }

    // Añadir un elemento al final
    void append(T e) override {
        insert(n, e);
    }

    // Añadir un elemento al principio
    void prepend(T e) override {
        insert(0, e);
    }

    // Eliminar un elemento en una posición
    T remove(int pos) override {
        if (pos < 0 || pos >= n) {
            throw out_of_range("Posición inválida");
        }

        Node<T>* temp;
        T removedData;

        if (pos == 0) {
            temp = first;
            first = first->getNext();
        } else {
            Node<T>* prev = first;
            for (int i = 0; i < pos - 1; i++) {
                prev = prev->getNext();
            }
            temp = prev->getNext();
            prev->setNext(temp->getNext());
        }

        removedData = temp->getData();
        delete temp;
        n--;
        return removedData;
    }

    // Obtener un elemento en una posición
    T get(int pos) const override {
        if (pos < 0 || pos >= n) {
            throw out_of_range("Posición inválida");
        }

        Node<T>* current = first;
        for (int i = 0; i < pos; i++) {
            current = current->getNext();
        }
        return current->getData();
    }

    // Buscar un elemento y devolver su posición
    int search(T e) const override {
        Node<T>* current = first;
        for (int i = 0; i < n; i++) {
            if (current->getData() == e) {
                return i;
            }
            current = current->getNext();
        }
        return -1;
    }

    // Indicar si la lista está vacía
    bool empty() const override {
        return n == 0;
    }

    // Obtener el tamaño de la lista
    int size() const override {
        return n;
    }

    // Sobrecarga del operador []
    T operator[](int pos) {
        return get(pos);
    }

    // Sobrecarga del operador <<
    friend ostream& operator<<(ostream& out, const ListLinked<T>& list) {
        Node<T>* current = list.first;
        out << "[";
        while (current != nullptr) {
            out << current->getData();
            if (current->getNext() != nullptr) {
                out << ", ";
            }
            current = current->getNext();
        }
        out << "]";
        return out;
    }
};

#endif // LISTLINKED_H

