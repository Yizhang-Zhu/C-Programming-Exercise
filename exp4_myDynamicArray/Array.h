#pragma once
#include <iostream>
#include <cassert>
using namespace std;

// ������ģ�嶨��
template <class T>
class Array			// ������
{
private:
	T* list;		// T ����ָ�룬���ڴ�Ŷ�̬����������ڴ��׵�ַ
	int size;		// �����С
public:
	Array(int sz = 50);			// ���캯��
	Array(const Array<T>& arr);	// �������캯��
	~Array();					// ��������

	// ���� = �����
	Array<T>& operator=(const Array<T>& arr);

	// ���� == �����
	bool operator==(const Array<T>& arr);

	// ���� != �����
	bool operator!=(const Array<T>& arr);

	// ���� [] �����
	T& operator[](int i);

	// [] ������� const ������
	const T& operator[](int i) const;

	// ���ص� T* ���͵�ת����ʹ Array ��������� C++ ��ͨ���������
	operator T* ();

	// �� T* ����ת����������� const ������
	operator const T* () const;

	// ȡ����Ĵ�С
	int getSize() const;

	// �޸�����Ĵ�С
	void resize(int size);
};

template<class T>
inline Array<T>::Array(int sz)
{
	assert(sz >= 0);
	size = sz;
	list = new T[sz];
}

template<class T>
inline Array<T>::Array(const Array<T>& arr)
{
	this->size = arr.size;
	list = new T[size];
	if (NULL == list)
	{
		cout << "alloc err!" << endl;
		exit(-1);
	}
	for (int i = 0; i < size; i++)
	{
		list[i] = arr.list[i];
	}
}

template<class T>
inline Array<T>::~Array()
{
	delete[] list;
	list = NULL;
}

template<class T>
inline Array<T>& Array<T>::operator=(const Array<T>& arr)
{
	if (&arr != this)
	{
		// ����������������С�� arr ��ͬ�����ͷ�����ԭ���ڴ棬���·���
		if (this->size != arr.size)
		{
			delete[] list;
			this->size = arr.size;
			list = new T[this->size];
		}
		for (int i = 0; i < this->size; ++i)
		{
			list[i] = arr.list[i];
		}
	}
	return *this;
}

template<class T>
inline bool Array<T>::operator==(const Array<T>& arr)
{
	if (this->size != arr.size)
	{
		return false;
	}
	// �ж������Ƿ���ͬ
	for (int i = 0; i < this->size; i++)
	{
		if (this->list[i] != arr.list[i])
		{
			return false;
		}
	}
	return true;
}

template<class T>
inline bool Array<T>::operator!=(const Array<T>& arr)
{
	return !(*this == arr);
}

template<class T>
inline T& Array<T>::operator[](int i)
{
	assert(i >= 0 && i < size);				// ��������±��Ƿ�Խ��
	return list[i];
}

template<class T>
inline const T& Array<T>::operator[](int i) const
{
	assert(i >= 0 && i < size);
	return list[i];
}

template<class T>
inline Array<T>::operator T* ()
{
	return list;							// ���ص�ǰ������˽��������׵�ַ
}

template<class T>
inline Array<T>::operator const T* () const
{
	return list;
}

template<class T>
inline int Array<T>::getSize() const
{
	return size;
}

template<class T>
inline void Array<T>::resize(int size)
{
	assert(size >= 0);					// ��� size �Ƿ�Ǹ�
	if (this->size == size)
	{
		return;
	}
	T* newList = new T[size];
	if (NULL == newList)
	{
		cout << "alloc err!" << endl;
		exit(-1);
	}

	int n = (size > this->size) ? this->size : size;

	for (int i = 0; i < n; i++)
	{
		newList[i] = list[i];
	}
	delete[] list;
	list = newList;
	this->size = size;
}