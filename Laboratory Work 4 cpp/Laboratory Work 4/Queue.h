#pragma once
#include <iostream>
#include <typeinfo>
#include <vector>
using namespace std;

template<typename m_Type>
class Queue {
private:
	vector<m_Type> m_Queue;

public:
	Queue(int length);
	~Queue();

	void m_Push(m_Type value);
	m_Type m_Pop();
	m_Type topLayer();
	void Print() const;

	bool operator==(const Queue& other);
	bool operator!=(const Queue& other);
};