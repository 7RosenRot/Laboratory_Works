#include "Stack.h"

template <typename m_Type>
Stack<m_Type>::Stack() {}

template <typename m_Type>
Stack<m_Type>::~Stack() {}

template<typename m_Type>
bool Stack<m_Type>::Empty() { return m_Stack.empty(); }

template <typename m_Type>
void Stack<m_Type>::Push(const m_Type& value) { m_Stack.push_back(value); }

template <typename m_Type>
m_Type Stack<m_Type>::Pop() {
    if (m_Stack.empty()) { cout << "Empty!"; }

    m_Type value = m_Stack.back();
    m_Stack.pop_back();
    return value;
}

template <typename m_Type>
void Stack<m_Type>::Print() const {
    for (size_t i = 0; i < m_Stack.size(); i += 1) { cout << m_Stack[i] << " "; }
    cout << endl;
}