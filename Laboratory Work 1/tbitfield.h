#pragma once;
#include <iostream>
#include <stdexcept>
using namespace std;

class TBitField {
private:
    int BitField_lenght = 0;
    int Memory_lenght = 0;
    unsigned int* ptr_Memory = nullptr;

public:
    TBitField(int lenght) : BitField_lenght(lenght) {
        if (BitField_lenght < 0) { throw invalid_argument("invalid bitfield length!"); }

        Memory_lenght = (BitField_lenght + 31) / 32;
        ptr_Memory = new unsigned int[Memory_lenght];

        for (int i = 0; i < Memory_lenght; i += 1) { ptr_Memory[i] = 0; }
    }

    TBitField(const TBitField& other) : Memory_lenght(other.Memory_lenght), BitField_lenght(other.BitField_lenght) {
        ptr_Memory = new unsigned int[Memory_lenght];

        for (int i = 0; i < Memory_lenght; i += 1) { ptr_Memory[i] = other.ptr_Memory[i]; }
    }

    ~TBitField() { delete[] ptr_Memory; }

    TBitField& operator=(const TBitField& other) {
        if (this != &other) {
            delete[] ptr_Memory;

            Memory_lenght = other.Memory_lenght;
            BitField_lenght = other.BitField_lenght;

            ptr_Memory = new unsigned int[Memory_lenght];

            for (int i = 0; i < Memory_lenght; i += 1) { ptr_Memory[i] = other.ptr_Memory[i]; }

            return *this;
        }
    }

    TBitField operator&(const TBitField& other) const {
        TBitField result(max(this->BitField_lenght, other.BitField_lenght));

        for (int i = 0; i < Memory_lenght; i += 1) {
            result.ptr_Memory[i] = ptr_Memory[i] & other.ptr_Memory[i];
        }

        return result;
    }

    TBitField operator|(const TBitField& other) const {
        TBitField result(max(this->BitField_lenght, other.BitField_lenght));

        for (int i = 0; i < Memory_lenght; i += 1) {
            result.ptr_Memory[i] = ptr_Memory[i] | other.ptr_Memory[i];
        }

        return result;
    }

    TBitField operator~() const {
        TBitField result(BitField_lenght);

        for (int i = 0; i < Memory_lenght; i += 1) {
            result.ptr_Memory[i] = ~ptr_Memory[i];
        }

        int Bit_extra = BitField_lenght % 32;
        if (Bit_extra > 0) {
            unsigned int BitField_mask = (1 << Bit_extra) - 1;
            result.ptr_Memory[Memory_lenght - 1] &= BitField_mask;
        }

        return result;
    }

    bool operator[](int index) const {
        if (index < 0 || index >= BitField_lenght) { throw out_of_range("Index out of range"); }

        int Index_next = index / 32;
        int Index_bit = index % 32;

        return (ptr_Memory[Index_next] >> Index_bit) & 1;
    }

    bool operator==(const TBitField& other) const {
        if (BitField_lenght != other.BitField_lenght) { return false; }
        
        for (int i = 0; i < Memory_lenght; i += 1) {
            if (ptr_Memory[i] != other.ptr_Memory[i]) { return false; }
        }

        return true;
    }

    bool operator!=(const TBitField& other) const { return !(*this == other); }

    int GetMemIndex(int bit) const { return bit / 32; }

    bool GetBit(int bit) const {
        if (bit >= BitField_lenght || bit < 0) { throw out_of_range("bit out of range!"); }

        return operator[](bit);
    }

    unsigned int GetMemMask(int bit) const { return 1 << (bit % 32); }

    int GetLength() const { return BitField_lenght; }

    void SetBit(int bit) const {
        if (bit >= BitField_lenght || bit < 0) { throw out_of_range("bit out of range!"); }

        int Index_next = GetMemIndex(bit);
        unsigned int Mask = GetMemMask(bit);

        ptr_Memory[Index_next] |= Mask;
    }

    void ClrBit(int bit) const {
        if (bit >= BitField_lenght || bit < 0) { throw out_of_range("bit out of range!"); }

        int Index_next = GetMemIndex(bit);
        unsigned int Mask = GetMemMask(bit);

        ptr_Memory[Index_next] &= ~Mask;
    }

    friend istream& operator>>(istream& m_istream, const TBitField& m_BitField) {
        for (int i = 0; i < m_BitField.GetLength(); i += 1) {
            int Bit;
            m_istream >> Bit;

            if (Bit == 1) { m_BitField.SetBit(i); }
            else if (Bit == 0) { m_BitField.ClrBit(i); }
        }

        return m_istream;
    }

    friend ostream& operator<<(ostream& m_ostream, const TBitField& m_BitField) {
        for (int i = 0; i < m_BitField.GetLength(); i += 1) {
            m_ostream << m_BitField.GetBit(i);
        }

        return m_ostream;
    }
};