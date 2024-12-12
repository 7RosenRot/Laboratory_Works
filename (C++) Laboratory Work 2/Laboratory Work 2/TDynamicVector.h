#pragma once
#include "Headers.h"

const int MAX_VECTOR_LENGTH = 100;

template<typename m_Type>
class TDynamicVector {
protected:
	size_t length = 0;
	m_Type* ptrMemory = nullptr;
public:
	TDynamicVector(size_t m_lenght = 1);
	TDynamicVector(m_Type* Vector, size_t m_length);
	TDynamicVector(const TDynamicVector& m_TDynamicVector);
	TDynamicVector(TDynamicVector&& m_TDynamicVecctor) noexcept;
	~TDynamicVector();

	TDynamicVector& operator=(const TDynamicVector& m_TDynamicVector);
	TDynamicVector& operator=(TDynamicVector&& m_TDynamicVector) noexcept;

	size_t size() const noexcept;
	m_Type& operator[](size_t index);
	const m_Type& operator[](size_t index) const;
	m_Type& findIndex(size_t index);
	const m_Type& findIndex(size_t index) const;

	bool operator==(const TDynamicVector& m_TDynamicMatrix) const noexcept;
	bool operator!=(const TDynamicVector& m_TDynamicMatrix) const noexcept;

	TDynamicVector operator+(m_Type value);
	TDynamicVector operator+(const TDynamicVector& m_TDynamicVector);
	TDynamicVector operator-(m_Type value);
	TDynamicVector operator-(const TDynamicVector& m_TDynamicVector);
	TDynamicVector operator*(m_Type value);
	m_Type operator*(const TDynamicVector& m_TDynamicVector) noexcept(noexcept(m_Type()));

	friend istream& operator>>(istream& m_istream, TDynamicVector& m_TDynamicVector) {
		for (size_t i = 0; i < m_TDynamicVector.length; i += 1) { m_istream >> m_TDynamicVector.ptrMemory[i]; }

		return m_istream;
	}
	
	friend ostream& operator<<(ostream& m_ostream, const TDynamicVector& m_TDynamicVector) {
		for (size_t i = 0; i < m_TDynamicVector.length; i += 1) { m_ostream << m_TDynamicVector.ptrMemory[i] << ' '; }

		return m_ostream;
	}
};