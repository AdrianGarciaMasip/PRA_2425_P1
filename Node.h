#ifndef NODE_H
#define NODE_H

#include <ostream>

// Declaración del espacio de nombres estándar
using namespace std;

template <typename T>
class Node {
private:
    T data;               // Dato almacenado en el nodo
    Node<T>* next;        // Puntero al siguiente nodo

public:
    // Constructor
    Node(T data, Node<T>* next = nullptr) : data(data), next(next) {}

    // Métodos para obtener y establecer el dato
    T getData() const { return data; }
    void setData(T value) { data = value; }

    // Métodos para obtener y establecer el siguiente nodo
    Node<T>* getNext() const { return next; }
    void setNext(Node<T>* nextNode) { next = nextNode; }

    // Operador de flujo para imprimir el nodo
    friend ostream& operator<<(ostream& out, const Node<T>& node) {
        out << node.data;
        return out;
    }
};

#endif // NODE_H

