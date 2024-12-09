#include "Queue.h"

template<typename m_Type>
Queue<m_Type>::Queue(int length) {
	if (length <= 0) { throw out_of_range("Incorrect length"); }
	
	m_Queue.reserve(length);
}

template<typename m_Type>
Queue<m_Type>::~Queue() {}

template<typename m_Type>
void Queue<m_Type>::m_Push(m_Type value) {
	if (m_Queue.size() == m_Queue.capacity()) { throw out_of_range("Not enough space!"); }

	m_Queue.insert(m_Queue.begin(), value);
}

template<typename m_Type>
m_Type Queue<m_Type>::m_Pop() {
	if (m_Queue.empty()) { throw out_of_range("Empty!"); }
	
	m_Type value = m_Queue.back();
	m_Queue.erase(m_Queue.end());
	return value;
}

template<typename m_Type>
m_Type Queue<m_Type>::topLayer() {
	if (m_Queue.empty()) { throw out_of_range("Empty!"); }

	return m_Queue.front();
}

template<typename m_Type>
void Queue<m_Type>::Print() const {
	for (size_t i = 0; i < m_Queue.size(); i += 1) { cout << m_Queue[i] << " "; }
	cout << ';' << endl;
}

template<typename m_Type>
bool Queue<m_Type>::operator==(const Queue& other) { return m_Queue.size(); }

template<typename m_Type>
bool Queue<m_Type>::operator!=(const Queue& other) { return !(*this == other); }