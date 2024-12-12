#include "TDynamicMatrix.h"

template<typename m_Type>
TDynamicMatrix<m_Type>::TDynamicMatrix(size_t m_length) : TDynamicVector<TDynamicVector<m_Type>>(m_length) {
	if (m_length < 0) { throw out_of_range("Incorrect length!"); }
	if (m_length >= MAX_MATRIX_LENGTH) { throw out_of_range("Max capacity reached!"); }

	for (size_t i = 0; i < length; i += 1) { ptrMemory[i] = TDynamicVector<m_Type>(length); }
}

template<typename m_Type>
bool TDynamicMatrix<m_Type>::operator==(const TDynamicMatrix& m_TDynamicMatrix) const noexcept {
	if (length != m_TDynamicMatrix.length) { return false; }

	for (size_t i = 0; i < length; i += 1) {
		if (ptrMemory[i] != m_TDynamicMatrix.ptrMemory[i]) { return false; }
	}

	return true;
}

template<typename m_Type>
TDynamicMatrix<m_Type> TDynamicMatrix<m_Type>::operator+(const TDynamicMatrix& m_TDynamicMatrix) {
	if (length != m_TDynamicMatrix.length) { throw out_of_range("Lenghts do not match!"); }

	TDynamicMatrix result(length);
	for (size_t i = 0; i < length; i += 1) { result[i] = ptrMemory[i] + m_TDynamicMatrix.ptrMemory[i]; }

	return result;
}

template<typename m_Type>
TDynamicMatrix<m_Type> TDynamicMatrix<m_Type>::operator-(const TDynamicMatrix& m_TDynamicMatrix) {
	if (length != m_TDynamicMatrix.length) { throw out_of_range("Lenghts do not match!"); }

	TDynamicMatrix result(length);
	for (size_t i = 0; i < length; i += 1) { result[i] = ptrMemory[i] - m_TDynamicMatrix.ptrMemory[i]; }

	return result;
}

template<typename m_Type>
TDynamicMatrix<m_Type> TDynamicMatrix<m_Type>::operator*(const m_Type& value) {
	if (length != length) { throw out_of_range("Lenghts do not match!"); }

	TDynamicMatrix result(length);
	for (size_t i = 0; i < length; i += 1) { result[i] = ptrMemory[i] * value; }

	return result;
}