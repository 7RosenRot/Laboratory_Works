#pragma once
#include "Headers.h"
#include "TDynamicVector.h"

const int MAX_MATRIX_LENGTH = 100;

template<typename m_Type>
class TDynamicMatrix : public TDynamicVector<TDynamicVector<m_Type>> {
private:
	using TDynamicVector<TDynamicVector<m_Type>>::length;
	using TDynamicVector<TDynamicVector<m_Type>>::ptrMemory;

public:
	TDynamicMatrix(size_t m_length = 1);

	using TDynamicVector<TDynamicVector<m_Type>>::operator[];
	bool operator==(const TDynamicMatrix& m_TDynamicMatrix) const noexcept;
	TDynamicMatrix operator+(const TDynamicMatrix& m_TDynamicMatrix);
	TDynamicMatrix operator-(const TDynamicMatrix& m_TDynamicMatrix);
	TDynamicMatrix operator*(const m_Type& value);

	friend istream& operator>>(istream& m_istream, TDynamicMatrix& m_TDynamicMatrix) {
		for (size_t i = 0; i < m_TDynamicMatrix.length; i += 1) { m_istream >> m_TDynamicMatrix.ptrMemory[i]; }

		return m_istream;
	}
	
	friend ostream& operator<<(ostream& m_ostream, const TDynamicMatrix& m_TDynamicMatrix) {
		for (size_t i = 0; i < m_TDynamicMatrix.length; i += 1) { 
			m_ostream << m_TDynamicMatrix.ptrMemory[i] << '\n';
		}

		return m_ostream;
	}
};