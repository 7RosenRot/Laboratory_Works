#pragma once;
#include "tbitfield.h"

class TSet {
private:
    int Value_max;
    TBitField m_BitField;
public:
    TSet(int value) : m_BitField(value), Value_max(value) {}

    TSet(const TSet& other) : m_BitField(other.m_BitField), Value_max(other.Value_max) {}

    TSet(const TBitField& other) : m_BitField(other), Value_max(other.GetLength()) {}

    operator TBitField() { return m_BitField; }

    int GetMaxPower(void) const { return Value_max; }

    void InsElem(const int Member) const {
        if (Member < 0 || Member >= Value_max) { throw out_of_range("Element out of range!"); }

        m_BitField.SetBit(Member);
    }

    void DelElem(const int Member) const {
        if (Member < 0 || Member >= Value_max) { throw out_of_range("Element out of range!"); }

        m_BitField.ClrBit(Member);
    }

    bool IsMember(const int Member) const {
        if (Member < 0 || Member >= Value_max) { throw out_of_range("Element out of range!"); }

        return m_BitField.GetBit(Member);
    }

    int operator==(const TSet& other) const { return m_BitField == other.m_BitField; }

    int operator!=(const TSet& other) const { return !(*this == other); }

    TSet& operator=(const TSet& other) {
        if (this != &other) {
            Value_max = other.Value_max;
            m_BitField = other.m_BitField;
        }

        return *this;
    }

    TSet operator+(const int Member) const {
        if (Member < 0 || Member >= Value_max) { throw out_of_range("Element out of range!"); }

        TSet result(*this);
        result.InsElem(Member);

        return result;
    }

    TSet operator+(const TSet& other) const {
        TSet result(max(this->Value_max, other.Value_max));

        for (int i = 0; i < result.GetMaxPower(); i += 1) {
            if ((i < this->m_BitField.GetLength() && this->IsMember(i)) || (i < other.m_BitField.GetLength() && other.IsMember(i))) { result.InsElem(i); }
        }

        return result;
    }

    TSet operator-(const int Member) const {
        if (Member < 0 || Member >= Value_max) { throw out_of_range("Element out of range!"); }

        TSet result(*this);
        result.DelElem(Member);
        return result;
    }

    TSet operator*(const TSet& other) const {
        if (this->m_BitField.GetLength() != other.m_BitField.GetLength()) { return 0; }

        TSet result(min(this->Value_max, other.Value_max));

        for (int i = 0; i < result.GetMaxPower(); i += 1) {
            if ((i < this->m_BitField.GetLength() && this->IsMember(i)) && (i < other.m_BitField.GetLength() && other.IsMember(i))) { result.InsElem(i); }
        }

        return result;
    }

    TSet operator~() const {
        TSet result(Value_max);
        for (int i = 0; i < Value_max; i += 1) {
            if (!this->IsMember(i)) { result.InsElem(i); }
        }

        return result;
    }

    friend istream& operator>>(istream m_istream, const TSet& m_Interaction) {
        int Member;
        while (m_istream >> Member) {
            if (Member < 0 || Member >= m_Interaction.Value_max) { throw out_of_range("Element out of range!"); }

            m_Interaction.InsElem(Member);
        }

        return m_istream;
    }
    
    friend ostream& operator<<(ostream m_ostream, const TSet& m_Interaction) {
        m_ostream << "{";
        bool Start = true;

        for (int i = 0; i < m_Interaction.Value_max; i += 1) {
            if (m_Interaction.IsMember(i)) {
                if (!Start) { m_ostream << ", "; }
                m_ostream << i;
                Start = false;
            }
        }

        m_ostream << "}";
        return m_ostream;
    }
};