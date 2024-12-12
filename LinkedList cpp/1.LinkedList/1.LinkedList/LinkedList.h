#pragma once

template<typename DataType>
class LinkedList {
private:
    template<typename DataType>
    class Node {
    public:
        DataType Value;
        Node* ptr_Next;

        Node(DataType Value = DataType(), Node* ptr_Next = nullptr) {
            this->Value = Value;
            this->ptr_Next = ptr_Next;
        };
    };

    int lenght;
    Node<DataType>* cell;

public:
    LinkedList(void);
    ~LinkedList(void);
    
    int getlen() { return lenght; }
    void remove_back();
    void push_back(DataType Value);
    void delete_list();
    DataType& operator[](const int Index);
};