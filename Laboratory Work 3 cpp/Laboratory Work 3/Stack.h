#pragma once
#include "Headers.h"
using namespace std;

template <typename m_Type>
class Stack {
private:
    vector<m_Type> m_Stack;
public:
    Stack();
    ~Stack();
  
    bool Empty();
    void Push(const m_Type& value);   
    m_Type Pop();
    void Print() const;
};