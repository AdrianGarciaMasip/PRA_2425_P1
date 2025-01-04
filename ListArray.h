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

    void insert(int pos, T e) override {
        if (pos < 0 || pos > n) throw std::out_of_range("Posición inválida");
        if (n == max) resize(max * 2);
        for (int i = n; i > pos; i--) {
            arr[i] = arr[i - 1];
        }
        arr[pos] = e;
        n++;
    }

    void append(T e) override {
        insert(n, e);
    }

    void prepend(T e) override {
        insert(0, e);
    }

    T remove(int pos) override {
        if (pos < 0 || pos >= n) throw std::out_of_range("Posición inválida");
        T removed = arr[pos];
        for (int i = pos; i < n - 1; i++) {
            arr[i] = arr[i + 1];
        }
        n--;
        return removed;
    }

    T get(int pos) const override {
        if (pos < 0 || pos >= n) throw std::out_of_range("Posición inválida");
        return arr[pos];
    }

    int search(T e) const override {
        for (int i = 0; i < n; i++) {
            if (arr[i] == e) return i;
        }
        return -1;
    }

    bool empty() const override {
        return n == 0;
    }

    int size() const override {
        return n;
    }

    T operator[](int pos) {
        return get(pos);
    }
};

#endif // LISTARRAY_H

