#include <LinkedList.h>

template<typename DataType>
LinkedList<DataType>::LinkedList(void) {
    lenght = 0;
    cell = nullptr;
};

template<typename DataType>
void LinkedList<DataType>::remove_back() {
    Node<DataType>* Temp = cell;

    cell = cell->ptr_Next;

    delete Temp;

    lenght -= 1;
};

template<typename DataType>
void LinkedList<DataType>::push_back(DataType Value) {
    if (cell == nullptr) {
        cell = new Node<DataType>(Value);
    }
    else {
        Node<DataType>* Temp = this->cell;

        while (Temp->ptr_Next != nullptr) { Temp = Temp->ptr_Next; }
        Temp->ptr_Next = new Node<DataType>(Value);
    }

    lenght += 1;
};

template<typename DataType>
DataType& LinkedList<DataType>::operator[](const int Index) {
    int Count = 0;
    Node<DataType>* Temp = this->cell;

    while (Temp != nullptr) {
        if (Count == Index) { return Temp->Value; }

        Temp = Temp->ptr_Next;
        Count += 1;
    }
};

template<typename DataType>
void LinkedList<DataType>::delete_list() {
    while (lenght > 0) {
        Node<DataType>* Temp = cell;

        cell = cell->ptr_Next;

        delete Temp;

        lenght -= 1;
    }
};

template<typename DataType>
LinkedList<DataType>::~LinkedList(void) {};