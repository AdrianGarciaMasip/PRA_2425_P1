#ifndef LISTARRAY_H
#define LISTARRAY_H

#include "List.h" 
#include <stdexcept> 

template <typename T>
class ListArray : public List<T> {
private:
    T* arr; 
    int max;
    int n; 

    // Método privado para redimensionar el array dinámico
    void resize(int new_size) {
        T* aux = new T[new_size]; 
        for (int i = 0; i < n; i++) {
            aux[i] = arr[i]; 
        }
        delete[] arr; 
        arr = aux; 
        max = new_size; 
    }

public:
    ListArray() : max(10), n(0) {
        arr = new T[max]; 
    }

    ~ListArray() {
        delete[] arr;
    }

    // Inserta un elemento en una posición específica
    void insert(int pos, T e) override {
        if (pos < 0 || pos > n) throw std::out_of_range("Posición inválida"); 
        if (n == max) resize(max * 2); 
        for (int i = n; i > pos; i--) {
            arr[i] = arr[i - 1]; 
        }
        arr[pos] = e; 
        n++;
    }

    // Agrega un elemento al final de la lista
    void append(T e) override {
        insert(n, e); 
    }

    // Agrega un elemento al inicio de la lista
    void prepend(T e) override {
        insert(0, e); 
    }

    // Elimina y devuelve el elemento en la posición dada
    T remove(int pos) override {
        if (pos < 0 || pos >= n) throw std::out_of_range("Posición inválida"); 
        T removed = arr[pos]; 
        for (int i = pos; i < n - 1; i++) {
            arr[i] = arr[i + 1]; 
        }
        n--; 
        return removed; 
    }

    // Devuelve el elemento en la posición dada
    T get(int pos) const override {
        if (pos < 0 || pos >= n) throw std::out_of_range("Posición inválida"); 
        return arr[pos];
    }

    // Busca un elemento en la lista y devuelve su posición, o -1 si no está
    int search(T e) const override {
        for (int i = 0; i < n; i++) {
            if (arr[i] == e) return i; 
        }
        return -1; 
    }

    // Devuelve true si la lista está vacía
    bool empty() const override {
        return n == 0;
    }

    // Devuelve el número de elementos en la lista
    int size() const override {
        return n;
    }

    // Sobrecarga del operador -> []
    T operator[](int pos) {
        return get(pos);
    }
};

#endif 
