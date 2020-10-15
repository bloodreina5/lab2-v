#include<MyVector.h>

const int MAX_MATRIX_SIZE = 10000;
template <class ValType>
class TMatrix : public TVector<TVector<ValType> >
{
public:
	TMatrix(int s = 10);
	TMatrix(const TMatrix& mt);                    // �����������
	TMatrix(const TVector<TVector<ValType> >& mt); // �������������� ����
	bool operator==(const TMatrix& mt) const;      // ���������
	bool operator!=(const TMatrix& mt) const;      // ���������
	TMatrix& operator= (const TMatrix& mt);        // ������������
	TMatrix  operator+ (const TMatrix& mt);        // ��������
	TMatrix  operator- (const TMatrix& mt);        // ���������

	// ���� / �����
	friend istream& operator>>(istream& in, TMatrix& mt)
	{
		for (int i = 0; i < mt.Size; i++)
			in >> mt.pVector[i];

		return in;
	}
	friend ostream& operator<<(ostream& out, const TMatrix& mt)
	{
		for (int i = 0; i < mt.Size; i++)
			out << mt.pVector[i] << endl;

		return out;
	}
};

template <class ValType>
TMatrix<ValType>::TMatrix(int s) : TVector<TVector<ValType> >(s)
{
	if ((s < 0) || (s > MAX_MATRIX_SIZE))
		throw "Wrong value";
	for (int i = 0; i < s; i++)
		pVector[i] = TVector<ValType>(s - i, i);
}

template <class ValType> // ����������� �����������
TMatrix<ValType>::TMatrix(const TMatrix<ValType>& mt) : TVector<TVector<ValType> >(mt) {}

template <class ValType> // ����������� �������������� ����
TMatrix<ValType>::TMatrix(const TVector<TVector<ValType>>& mt) : TVector<TVector<ValType> >(mt) {}

template <class ValType> // ���������
bool TMatrix<ValType>::operator==(const TMatrix<ValType>& mt) const
{
	if (Size != mt.Size)
		return false;
	else
	{
		for (int i = 0; i < Size; i++)
			if (pVector[i] != mt.pVector[i]) return false;

		return true;
	}
}

template <class ValType> // ���������
bool TMatrix<ValType>::operator!=(const TMatrix<ValType>& mt) const
{
	return !(*this == mt);
}

template <class ValType> // ������������
TMatrix<ValType>& TMatrix<ValType>::operator=(const TMatrix<ValType>& mt)
{
	if (this != &mt)
	{
		if (mt.Size != Size)
		{
			Size = mt.Size;
			delete[] pVector;
			pVector = new TVector<ValType>[Size];
		}
		StartIndex = mt.StartIndex;
		for (int i = 0; i < Size; i++)
			pVector[i] = mt.pVector[i];
	}
	return *this;
}

template <class ValType> // ��������
TMatrix<ValType> TMatrix<ValType>::operator+(const TMatrix<ValType>& mt)
{
	if (Size != mt.Size)
		throw "Wrong value";
	TMatrix<ValType> temp(Size);
	for (int i = 0; i < Size; i++)
		temp.pVector[i] = pVector[i] + mt.pVector[i];

	return temp;
}

template <class ValType> // ���������
TMatrix<ValType> TMatrix<ValType>::operator-(const TMatrix<ValType>& mt)
{
	if (Size != mt.Size)
		throw "Wrong value";
	TMatrix<ValType> temp(Size);
	for (int i = 0; i < Size; i++)
		temp.pVector[i] = pVector[i] - mt.pVector[i];

	return temp;
}