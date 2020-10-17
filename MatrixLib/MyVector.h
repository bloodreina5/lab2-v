#ifndef _MY_VECTOR_
#define _MY_VECTOR_

#include <iostream>

using namespace std;

const int MAX_VECTOR_SIZE = 100000;

//������ �������
template <class T>
class TVector
{
protected:
    T* x;
    int length;

public:
    TVector();
    TVector(int _v);
    TVector(int s, int si);
    TVector(const TVector& v); // ����������� �����������
    virtual ~TVector();

    int GetSize() { return length; } // ������ �������

    T& operator[](int pos);            // ������
    bool operator==(const TVector& v) const; // ���������
    TVector& operator=(const TVector& v);    // ������������

    // ��������� ��������
    TVector operator+(const T& val); // ���������
    TVector operator-(const T& val); // �������
    TVector operator*(const T& val); // ��������
    TVector operator/(const T& val); //������

    // ��������� ��������
    TVector operator+(const TVector& v); // ��������
    TVector operator-(const TVector& v); // ���������
    TVector operator*(const TVector& v); // ��������� ������������

    // ����-�����
    friend istream& operator>>(istream& in, TVector& v)
    {
        for (int i = 0; i < v.length; i++)
        {
            in >> v.x[i];
        }
        return in;
    }

    friend ostream& operator<<(ostream& out, const TVector& v)
    {
        for (int i = 0; i < v.length; i++)
        {
            out << v.x[i] << '\t';
        }
        return out;
    }
};

template <class T>
inline TVector<T>::TVector()
{
    length = NULL;
}

template <class T>
TVector<T>::TVector(int v)
{
    if (v < 0 || v > MAX_VECTOR_SIZE)
    {
        throw logic_error("ERROR");
    }

    length = v;
    x = new T[length];

    for (int i = 0; i < length; i++)
    {
        x[i] = v;
    }
}

template <class T>
TVector<T>::TVector(int s, int si)
{
    if (si < 0)
    {
        throw logic_error("ERROR");
    }

    length = s;
    x = new T[length];

    for (int i = 0; i < length; i++)
    {
        x[i] = si;
    }
}

template <class T> //����������� �����������
TVector<T>::TVector(const TVector<T>& v)
{
    length = v.length;
    x = new T[length];

    for (int i = 0; i < length; i++)
    {
        x[i] = v.x[i];
    }
}

template <class T>
TVector<T>::~TVector()
{
    length = NULL;

    if (x != 0)
    {
        delete[] x;
    }

    x = NULL;
}

template <class T> // ������
T& TVector<T>::operator[](int index)
{
    if (index < 0 || index > length)
    {
        throw logic_error("ERROR");
    }

    if ((index >= 0) && (index < length))
    {
        return x[index];
    }

    return x[0];
}

template <class T> // ���������
bool TVector<T>::operator==(const TVector& v) const
{
    bool res = true;
    if (length != v.length)
    {
        res = false;
    }

    for (int i = 0; i < length; i++)
    {
        if (x[i] != v.x[i])
        {
            res = false;
        }
    }
    return res;
}

template <class T> //������������
TVector<T>& TVector<T>::operator=(const TVector& v)
{
    if (this == &v)
    {
        return *this;
    }

    length = v.length;
    x = new T[length];

    for (int i = 0; i < length; i++)
    {
        x[i] = v.x[i];
    }
    return *this;
}

template <class T> //���������
TVector<T> TVector<T>::operator+(const T& val)
{
    TVector<T> res;
    res.length = length;
    res.x = new T[res.length];

    for (int i = 0; i < res.length; i++)
    {
        res.x[i] = x[i] + val;
    }
    return res;
}

template <class T> //�������
TVector<T> TVector<T>::operator-(const T& val)
{
    TVector<T> res;
    res.length = length;
    res.x = new T[res.length];

    for (int i = 0; i < res.length; i++)
    {
        res.x[i] = x[i] - val;
    }
    return res;
}

template <class T> //��������
TVector<T> TVector<T>::operator*(const T& val)
{
    TVector<T> res;
    res.length = length;
    res.x = new T[res.length];

    for (int i = 0; i < res.length; i++)
    {
        res.x[i] = x[i] * val;
    }
    return res;
}

template <class T>
inline TVector<T> TVector<T>::operator/(const T& val)
{
    TVector<T> res;
    res.length = length;
    res.x = new T[res.length];

    for (int i = 0; i < res.length; i++)
    {
        res.x[i] = x[i] / val;
    }
    return res;
}

template <class T> //��������
TVector<T> TVector<T>::operator+(const TVector<T>& v)
{
    if (v.length != length)
    {
        throw logic_error("ERROR");
    }

    TVector<T> res;
    res.length = length;
    res.x = new T[res.length];

    for (int i = 0; i < res.length; i++)
    {
        res.x[i] = x[i] + v.x[i];
    }
    return res;
}

template <class T> //���������
TVector<T> TVector<T>::operator-(const TVector<T>& v)
{
    if (v.length != length)
    {
        throw logic_error("ERROR");
    }

    TVector<T> res;
    res.length = length;
    res.x = new T[res.length];

    for (int i = 0; i < res.length; i++)
    {
        res.x[i] = x[i] - v.x[i];
    }
    return res;
}

template <class T> //��������� ������������
TVector<T> TVector<T>::operator*(const TVector<T>& v)
{
    if (v.length != length)
    {
        throw logic_error("ERROR");
    }

    TVector<T> res;
    res.length = length;
    res.x = new T[res.length];

    for (int i = 0; i < res.length; i++)
    {
        res.x[i] = x[i] * v.x[i];
    }
    return res;
}
#endif