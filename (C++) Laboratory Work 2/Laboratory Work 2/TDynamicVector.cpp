#include "TDynamicVector.h"

template<typename m_Type>
TDynamicVector<m_Type>::TDynamicVector(size_t m_length) : length(m_length) {
	if (length <= 0) { throw out_of_range("Incorrect length!"); }
	if (length > MAX_VECTOR_LENGTH) { throw out_of_range("Max capacity reached!"); }

	ptrMemory = new m_Type[length]();
}

template<typename m_Type>
TDynamicVector<m_Type>::TDynamicVector(m_Type* Vector, size_t m_length) : length(m_length) {
	assert(Vector != nullptr);
	if (length > MAX_VECTOR_LENGTH) { throw out_of_range("Max capacity reached!"); }

	ptrMemory = new m_Type[length];
	copy(Vector, Vector + length, ptrMemory);
}

template<typename m_Type>
TDynamicVector<m_Type>::TDynamicVector(const TDynamicVector& m_TDynamicVector) : length(m_TDynamicVector.length) {
	ptrMemory = new m_Type[length];
	copy(m_TDynamicVector.ptrMemory, m_TDynamicVector.ptrMemory + length, ptrMemory);
}

template<typename m_Type>
TDynamicVector<m_Type>::TDynamicVector(TDynamicVector&& m_TDynamicVector) noexcept : length(m_TDynamicVector.length),
ptrMemory(m_TDynamicVector.ptrMemory) {
	m_TDynamicVector.length = 0;
	m_TDynamicVector.ptrMemory = nullptr;
}

template<typename m_Type>
TDynamicVector<m_Type>::~TDynamicVector() { delete[] ptrMemory; }

template<typename m_Type>
TDynamicVector<m_Type>& TDynamicVector<m_Type>::operator=(const TDynamicVector& m_TDynamicVector) {
	if (this != &m_TDynamicVector) {
		delete[] ptrMemory;
		length = m_TDynamicVector.length;
		ptrMemory = new m_Type[length];
		copy(m_TDynamicVector.ptrMemory, m_TDynamicVector.ptrMemory + length, ptrMemory);
	}
	return *this;
}

template<typename m_Type>
TDynamicVector<m_Type>& TDynamicVector<m_Type>::operator=(TDynamicVector&& m_TDynamicVector) noexcept {
	if (this != &m_TDynamicVector) {
		delete[] ptrMemory;
		length = m_TDynamicVector.length;
		ptrMemory = m_TDynamicVector.ptrMemory;
		m_TDynamicVector.length = 0;
		m_TDynamicVector.ptrMemory = nullptr;
	}
	return *this;
}

template<typename m_Type>
size_t TDynamicVector<m_Type>::size() const noexcept { return length; }

template<typename m_Type>
m_Type& TDynamicVector<m_Type>::operator[](size_t index) {
	if (index >= length) { throw out_of_range("Index out of range!"); }
	
	return ptrMemory[index];
}

template<typename m_Type>
const m_Type& TDynamicVector<m_Type>::operator[](size_t index) const {
	if (index >= length) { throw out_of_range("Index out of range!"); }
	
	return ptrMemory[index];
}

template<typename m_Type>
m_Type& TDynamicVector<m_Type>::findIndex(size_t index) {
	if (index >= length) { throw out_of_range("Index out of range!"); }

	return ptrMemory[index];
}

template<typename m_Type>
const m_Type& TDynamicVector<m_Type>::findIndex(size_t index) const {
	if (index >= length) { throw out_of_range("Index out of range!"); }

	return ptrMemory[index];
}

template<typename m_Type>
bool TDynamicVector<m_Type>::operator==(const TDynamicVector& m_TDynamicVector) const noexcept {
	if (length != m_TDynamicVector.length) { throw out_of_range("Incorrect length!"); }
	
	return equal(ptrMemory, ptrMemory + length, m_TDynamicVector.ptrMemory);
}

template<typename m_Type>
bool TDynamicVector<m_Type>::operator!=(const TDynamicVector& m_TDynamicVector) const noexcept { return !(*this == m_TDynamicVector); }

template<typename m_Type>
TDynamicVector<m_Type> TDynamicVector<m_Type>::operator+(m_Type value) {
	TDynamicVector result(length);
	for (size_t i = 0; i < length; i += 1) { result[i] = ptrMemory[i] + value; }
	
	return result;
}

template<typename m_Type>
TDynamicVector<m_Type> TDynamicVector<m_Type>::operator+(const TDynamicVector& m_TDynamicVector) {
	if (length != m_TDynamicVector.length) { throw out_of_range("Lenghts do not match!"); }
	
	TDynamicVector result(length);
	for (size_t i = 0; i < length; i += 1) { result[i] = ptrMemory[i] + m_TDynamicVector.ptrMemory[i]; }

	return result;
}

template<typename m_Type>
TDynamicVector<m_Type> TDynamicVector<m_Type>::operator-(m_Type value) {
	TDynamicVector result(length);
	for (size_t i = 0; i < length; i += 1) { result[i] = ptrMemory[i] - value; }

	return result;
}

template<typename m_Type>
TDynamicVector<m_Type> TDynamicVector<m_Type>::operator-(const TDynamicVector& m_TDynamicVector) {
	if (length != m_TDynamicVector.length) { throw out_of_range("Lenghts do not match!"); }
	
	TDynamicVector result(length);
	for (size_t i = 0; i < length; i += 1) { result[i] = ptrMemory[i] - m_TDynamicVector.ptrMemory[i]; }

	return result;
}

template<typename m_Type>
TDynamicVector<m_Type> TDynamicVector<m_Type>::operator*(m_Type value) {
	TDynamicVector result(length);
	for (size_t i = 0; i < length; i += 1) { result[i] = ptrMemory[i] * value; }

	return result;
}

template<typename m_Type>
m_Type TDynamicVector<m_Type>::operator*(const TDynamicVector& m_TDynamicVector) noexcept(noexcept(m_Type())) {
	if (length != m_TDynamicVector.length) { throw out_of_range("Lenghts do not match!"); }
	
	m_Type result = m_Type();
	for (size_t i = 0; i < length; i += 1) { result += ptrMemory[i] * m_TDynamicVector.ptrMemory[i]; }

	return result;
}