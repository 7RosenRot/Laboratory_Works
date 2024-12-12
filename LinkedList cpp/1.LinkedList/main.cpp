#include <LinkedList.h>
#include <LinkedList.cpp>
#include <iostream>
using namespace std;

int main() {
    LinkedList<char> array;

    array.push_back('a');

    cout << array[0];

    array.delete_list();

    return 0;
}