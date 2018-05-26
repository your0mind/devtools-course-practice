// Copyright 2018 Aglikov Ilya

#include "include/bits_array.h"

#include <stdexcept>


int bitSize = sizeof(unsigned int) * 8;  // bitSize = unsigned intbitSize

BitsArray::BitsArray(int len) {
    if (len > 0) {
        BitLen = len;
        MemLen = (BitLen % bitSize) ? (BitLen / bitSize + 1) : (BitLen / bitSize);
        pMem = new unsigned int[MemLen];
        for (int i = 0; i < MemLen; i++)
            pMem[i] = 0;
    }
    else 
        throw std::invalid_argument("Invalid argument in constructor!");
}

BitsArray::BitsArray(const BitsArray &bf) {  // конструктор копирования
    BitLen = bf.BitLen;
    MemLen = bf.MemLen;
    pMem = new unsigned int[MemLen];
    for (int i = 0; i < MemLen; i++)
        pMem[i] = bf.pMem[i];
}

BitsArray::~BitsArray() {
    delete[] pMem;
}

int BitsArray::GetMemIndex(const int n) const {  // индекс Мем для бита n
    if (n > -1 && n < BitLen)
        return (n / bitSize);
    else 
        throw std::out_of_range("Out of range in \"GetMemIndex\"");
}

unsigned int BitsArray::GetMemMask(const int n) const {  // битовая маска для бита n
    if (n > -1 && n < BitLen)
    {
        unsigned int mask = 1 << n % bitSize;
        return mask;
    }
    else
        throw std::out_of_range("Out of range in \"GetMemMask\"");
}

// доступ к битам битового поля

int BitsArray::GetLength(void) const {  // получить длину (к-во битов)
    return BitLen;
}

void BitsArray::SetBit(const int n) {  // установить бит
    if (n > -1 && n < BitLen)
    {
        pMem[GetMemIndex(n)] |= GetMemMask(n);
    }
    else 
        throw std::out_of_range("Out of range in \"SetBit\"");
}

void BitsArray::ClrBit(const int n) {  // очистить бит
    if (n > -1 && n < BitLen)
    {
        pMem[GetMemIndex(n)] &= ~GetMemMask(n);
    }
    else 
        throw std::out_of_range("Out of range in \"ClrBit\"");
}

int BitsArray::GetBit(const int n) const {  // получить значение бита
    if (n > -1 && n < BitLen)
    {
        return (pMem[GetMemIndex(n)] & GetMemMask(n)) ? 1 : 0;
    }
    else 
        throw std::out_of_range("Out of range in \"GetBit\"");
}

// битовые операции

BitsArray& BitsArray::operator=(const BitsArray &bf) {  // присваивание
    if (this != &bf)
    {
        BitLen = bf.BitLen;
        if (MemLen != bf.MemLen)
        {
            MemLen = bf.MemLen;
            pMem = new unsigned int[MemLen];
        }
        for (int i = 0; i < MemLen; i++)
            pMem[i] = bf.pMem[i];
    }
    return *this;
}

int BitsArray::operator==(const BitsArray &bf) const {  // сравнение
    if (BitLen != bf.BitLen || MemLen != bf.MemLen)
        return 0;
    else
        for (int i = 0; i < MemLen; i++)
            if (pMem[i] != bf.pMem[i])
                return 0;
    return 1;
}

int BitsArray::operator!=(const BitsArray &bf) const {  // сравнение
    if (BitLen != bf.BitLen || MemLen != bf.MemLen)
        return 1;
    else
        for (int i = 0; i < MemLen; i++)
            if (pMem[i] != bf.pMem[i])
                return 1;
    return 0;
}

BitsArray BitsArray::operator|(const BitsArray &bf) {  // операция "или"
    int maxMem = (BitLen > bf.BitLen) ? BitLen : bf.BitLen;
    BitsArray tmp(maxMem);
    for (int i = 0; i < MemLen; i++)
        tmp.pMem[i] = pMem[i];
    for (int i = 0; i < MemLen; i++)
        tmp.pMem[i] |= bf.pMem[i];
    return tmp;
}

BitsArray BitsArray::operator&(const BitsArray &bf) {  // операция "и"
    int maxMem = (BitLen > bf.BitLen) ? BitLen : bf.BitLen;
    BitsArray tmp(maxMem);
    for (int i = 0; i < MemLen; i++)
        tmp.pMem[i] = pMem[i];
    for (int i = 0; i < MemLen; i++)
        tmp.pMem[i] &= bf.pMem[i];
    return tmp;
}

BitsArray BitsArray::operator~(void) {  // отрицание
    BitsArray tmp(BitLen);
    for (int i = 0; i < BitLen; i++)
        if (GetBit(i) == 0)
            tmp.SetBit(i);
    return tmp;
}

// ввод/вывод

std::istream &operator >> (std::istream &istr, BitsArray &bf) {  // ввод
    char bit;
    int i = 0;
    while (i < bf.BitLen)
    {
        istr >> bit;
        if (bit == '0')
            bf.ClrBit(i);
        else
            if (bit == '1')
                bf.SetBit(i);
            else
                return istr;
        i++;
    }
    return istr;
}

std::ostream &operator<<(std::ostream &ostr, const BitsArray &bf) {  // вывод
    for (int i = 0; i < bf.BitLen; i++)
    {
        ostr << bf.GetBit(i);
    }
    ostr << std::endl;
    return ostr;
}