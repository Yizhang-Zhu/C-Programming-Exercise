#pragma once
#include <iostream>
#include <cassert>
using namespace std;

// 数组类模板定义
template <class T>
class Array			// 数组类
{
private:
	T* list;		// T 类型指针，用于存放动态分配的数组内存首地址
	int size;		// 数组大小
public:
	Array(int sz = 50);			// 构造函数
	Array(const Array<T>& arr);	// 拷贝构造函数
	~Array();					// 析构函数

	// 重载 = 运算符
	Array<T>& operator=(const Array<T>& arr);

	// 重载 == 运算符
	bool operator==(const Array<T>& arr);

	// 重载 != 运算符
	bool operator!=(const Array<T>& arr);

	// 重载 [] 运算符
	T& operator[](int i);

	// [] 运算符对 const 的重载
	const T& operator[](int i) const;

	// 重载到 T* 类型的转换，使 Array 对象可以起到 C++ 普通数组的作用
	operator T* ();

	// 到 T* 类型转换操作符针对 const 的重载
	operator const T* () const;

	// 取数组的大小
	int getSize() const;

	// 修改数组的大小
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
		// 如果本对象中数组大小与 arr 不同，则释放数组原有内存，重新分配
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
	// 判断内容是否相同
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
	assert(i >= 0 && i < size);				// 检查数组下标是否越界
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
	return list;							// 返回当前对象中私有数组的首地址
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
	assert(size >= 0);					// 检查 size 是否非负
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