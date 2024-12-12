// ННГУ, ИИТММ, Курс "Алгоритмы и структуры данных"
//
// Copyright (c) Сысоев А.В.
//
//

#ifndef __TDynamicMatrix_H__
#define __TDynamicMatrix_H__

#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <cassert>

using namespace std;

const int MAX_VECTOR_SIZE = 100000000;
const int MAX_MATRIX_SIZE = 10000;

template<typename m_Type>
class TDynamicVector {
protected:
	size_t length = 0;
	m_Type* ptrMemory = nullptr;
public:
	TDynamicVector(size_t m_length = 1) : length(m_length) {
		if (length <= 0) { throw out_of_range("Incorrect length!"); }
		if (length > MAX_VECTOR_SIZE) { throw out_of_range("Max capacity reached!"); }

		ptrMemory = new m_Type[length]();
	}
	
	TDynamicVector(m_Type* Vector, size_t m_length) : length(m_length) {
		assert(Vector != nullptr);
		if (length > MAX_VECTOR_SIZE) { throw out_of_range("Max capacity reached!"); }

		ptrMemory = new m_Type[length];
		copy(Vector, Vector + length, ptrMemory);
	}
	
	TDynamicVector(const TDynamicVector& m_TDynamicVector) : length(m_TDynamicVector.length) {
		ptrMemory = new m_Type[length];
		copy(m_TDynamicVector.ptrMemory, m_TDynamicVector.ptrMemory + length, ptrMemory);
	}
	
	TDynamicVector(TDynamicVector&& m_TDynamicVector) noexcept : length(m_TDynamicVector.length),
		ptrMemory(m_TDynamicVector.ptrMemory) {
		m_TDynamicVector.length = 0;
		m_TDynamicVector.ptrMemory = nullptr;
	}
	
	~TDynamicVector() { delete[] ptrMemory; }
	
	TDynamicVector& operator=(const TDynamicVector& m_TDynamicVector) {
		if (this != &m_TDynamicVector) {
			delete[] ptrMemory;
			length = m_TDynamicVector.length;
			ptrMemory = new m_Type[length];
			copy(m_TDynamicVector.ptrMemory, m_TDynamicVector.ptrMemory + length, ptrMemory);
		}
		return *this;
	}
	
	TDynamicVector& operator=(TDynamicVector&& m_TDynamicVector) noexcept {
		if (this != &m_TDynamicVector) {
			delete[] ptrMemory;
			length = m_TDynamicVector.length;
			ptrMemory = m_TDynamicVector.ptrMemory;
			m_TDynamicVector.length = 0;
			m_TDynamicVector.ptrMemory = nullptr;
		}
		return *this;
	}
	
	size_t size() const noexcept { return length; }
	
	m_Type& operator[](size_t index) {
		if (index >= length) { throw out_of_range("Index out of range!"); }

		return ptrMemory[index];
	}
	
	const m_Type& operator[](size_t index) const {
		if (index >= length) { throw out_of_range("Index out of range!"); }

		return ptrMemory[index];
	}
	
	m_Type& at(size_t index) {
		if (index >= length) { throw out_of_range("Index out of range!"); }

		return ptrMemory[index];
	}

	const m_Type& at(size_t index) const {
		if (index >= length) { throw out_of_range("Index out of range!"); }

		return ptrMemory[index];
	}

	bool operator==(const TDynamicVector& m_TDynamicVector) const noexcept {
		if (length != m_TDynamicVector.length) { return false; }

		return equal(ptrMemory, ptrMemory + length, m_TDynamicVector.ptrMemory);
	}
	
	bool operator!=(const TDynamicVector& m_TDynamicVector) const noexcept { return !(*this == m_TDynamicVector); }
	
	TDynamicVector operator+(m_Type value) {
		TDynamicVector result(length);
		for (size_t i = 0; i < length; i += 1) { result[i] = ptrMemory[i] + value; }

		return result;
	}
	
	TDynamicVector operator+(const TDynamicVector& m_TDynamicVector) {
		if (length != m_TDynamicVector.length) { throw out_of_range("Lenghts do not match!"); }

		TDynamicVector result(length);
		for (size_t i = 0; i < length; i += 1) { result[i] = ptrMemory[i] + m_TDynamicVector.ptrMemory[i]; }

		return result;
	}
	
	TDynamicVector operator-(m_Type value) {
		TDynamicVector result(length);
		for (size_t i = 0; i < length; i += 1) { result[i] = ptrMemory[i] - value; }

		return result;
	}
	
	TDynamicVector operator-(const TDynamicVector& m_TDynamicVector) {
		if (length != m_TDynamicVector.length) { throw out_of_range("Lenghts do not match!"); }

		TDynamicVector result(length);
		for (size_t i = 0; i < length; i += 1) { result[i] = ptrMemory[i] - m_TDynamicVector.ptrMemory[i]; }

		return result;
	}
	
	TDynamicVector operator*(m_Type value) {
		TDynamicVector result(length);
		for (size_t i = 0; i < length; i += 1) { result[i] = ptrMemory[i] * value; }

		return result;
	}
	
	m_Type operator*(const TDynamicVector& m_TDynamicVector) noexcept(noexcept(m_Type())) {
		if (length != m_TDynamicVector.length) { throw out_of_range("Lenghts do not match!"); }

		m_Type result = m_Type();
		for (size_t i = 0; i < length; i += 1) { result += ptrMemory[i] * m_TDynamicVector.ptrMemory[i]; }

		return result;
	}

	friend istream& operator>>(istream& m_istream, TDynamicVector& m_TDynamicVector) {
		for (size_t i = 0; i < m_TDynamicVector.length; i += 1) { m_istream >> m_TDynamicVector.ptrMemory[i]; }

		return m_istream;
	}

	friend ostream& operator<<(ostream& m_ostream, const TDynamicVector& m_TDynamicVector) {
		for (size_t i = 0; i < m_TDynamicVector.length; i += 1) { m_ostream << m_TDynamicVector.ptrMemory[i] << ' '; }

		return m_ostream;
	}
};

template<typename m_Type>
class TDynamicMatrix : public TDynamicVector<TDynamicVector<m_Type>> {
private:
	using TDynamicVector<TDynamicVector<m_Type>>::length;
	using TDynamicVector<TDynamicVector<m_Type>>::ptrMemory;

public:
	TDynamicMatrix(size_t m_length = 1) : TDynamicVector<TDynamicVector<m_Type>>(m_length) {
		if (m_length < 0) { throw out_of_range("Incorrect length!"); }
		if (m_length >= MAX_MATRIX_SIZE) { throw out_of_range("Max capacity reached!"); }

		for (size_t i = 0; i < length; i += 1) { ptrMemory[i] = TDynamicVector<m_Type>(length); }
	}
	
	using TDynamicVector<TDynamicVector<m_Type>>::operator[];

	bool operator==(const TDynamicMatrix& m_TDynamicMatrix) const noexcept {
		if (length != m_TDynamicMatrix.length) { return false; }

		for (size_t i = 0; i < length; i += 1) {
			if (ptrMemory[i] != m_TDynamicMatrix.ptrMemory[i]) { return false; }
		}

		return true;
	}

	TDynamicMatrix operator+(const TDynamicMatrix& m_TDynamicMatrix) {
		if (length != m_TDynamicMatrix.length) { throw out_of_range("Lenghts do not match!"); }

		TDynamicMatrix result(length);
		for (size_t i = 0; i < length; i += 1) { result[i] = ptrMemory[i] + m_TDynamicMatrix.ptrMemory[i]; }

		return result;
	}
	
	TDynamicMatrix operator-(const TDynamicMatrix& m_TDynamicMatrix) {
		if (length != m_TDynamicMatrix.length) { throw out_of_range("Lenghts do not match!"); }

		TDynamicMatrix result(length);
		for (size_t i = 0; i < length; i += 1) { result[i] = ptrMemory[i] - m_TDynamicMatrix.ptrMemory[i]; }

		return result;
	}

	TDynamicMatrix operator*(const m_Type& value) {
		TDynamicMatrix result(length);
		for (size_t i = 0; i < length; i += 1) { result[i] = ptrMemory[i] * value; }

		return result;
	}

	friend istream& operator>>(istream& m_istream, TDynamicMatrix& m_TDynamicMatrix) {
		for (size_t i = 0; i < m_TDynamicMatrix.length; i += 1) { m_istream >> m_TDynamicMatrix.ptrMemory[i]; }

		return m_istream;
	}

	friend ostream& operator<<(ostream& m_ostream, const TDynamicMatrix& m_TDynamicMatrix) {
		for (size_t i = 0; i < m_TDynamicMatrix.length; i += 1) { m_ostream << m_TDynamicMatrix.ptrMemory[i] << '\n'; }

		return m_ostream;
	}
};

#endif