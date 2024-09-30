#ifndef ARRAY_H_
#define ARRAY_H_

#include <ostream>

template<class T>
class Array
{
	int physicalSize, logicalSize;
	char delimiter;
	T* arr;
public:
	Array(char delimiter = ' ');
	Array(const Array& other);
	Array(const Array&& other);//+
	~Array();

	int getLogicalSize()     const { return logicalSize; };
	const Array& operator=(const Array& other);
	const Array& operator=(const Array&& other);//+
	const Array& operator+=(const T& newVal);

	friend ostream& operator<<(ostream& os, const Array& arr)
	{
		if (typeid(os) == typeid(ofstream))
		{
			os << arr.getLogicalSize() << endl;
			for (int i = 0; i < arr.logicalSize; i++)
				os << arr.arr[i] << endl;

		}
		else
		{
			for (int i = 0; i < arr.logicalSize; i++)
				os << arr.arr[i] << arr.delimiter;
		}
		return os;
	}

	friend istream& operator>>(istream& is,  Array & arr)
	{
		if (typeid(is) == typeid(ifstream))
		{
			int size;
			is >> size;
			for (int i=0; i < size; i++)
			{
				T tmp;
				is >> tmp;
				arr += tmp;
			}

		}
		else
		{
			T a;
		    is >> a;
		    arr += a;
		

		}
		return is;
	}
};

//-------------------------------------------------------------------------------//
template<class T>
Array<T>::Array(char delimiter) : physicalSize(1), logicalSize(0), delimiter(delimiter)
{
	arr = new T[physicalSize];
}
// -------------------------------------------------------------------------------//

//------------------------------------------------------------------------------- //
template<class T>
Array<T>::Array(const Array& other) : arr(NULL)
{
	*this = other;
}
// ------------------------------------------------------------------------------- //

//------------------------------------------------------------------------------- //
template<class T>
Array<T>::Array(const Array&& other) : arr(NULL)
{
	*this = std::move(other);
}
// ------------------------------------------------------------------------------- //

//------------------------------------------------------------------------------//
template<class T>
Array<T>::~Array()
{

	delete[]arr;

}
//------------------------------------------------------------------------------//

//------------------------------------------------------------------------------//
template<class T>
const Array<T>& Array<T>::operator=(const Array<T>& other)
{
	if (this != &other)
	{
		delete[]arr;
		physicalSize = other.physicalSize;
		logicalSize = other.logicalSize;
		delimiter = other.delimiter;
		arr = new T[physicalSize];
		for (int i = 0; i < logicalSize; i++)
			arr[i] = other.arr[i];
	}
	return *this;
}
//------------------------------------------------------------------------------//

//------------------------------------------------------------------------------//
template<class T>
const Array<T>& Array<T>::operator=(const Array<T>&& other)
{
	
		physicalSize = other.physicalSize;
		logicalSize = other.logicalSize;
		delimiter = other.delimiter;
		std::swap(arr, other.arr);
	
	return *this;
}
//------------------------------------------------------------------------------//

//------------------------------------------------------------------------------//
template<class T>
const Array<T>& Array<T>::operator+=(const T& newVal)
{
	if (logicalSize == physicalSize)
	{
		physicalSize = physicalSize * 2;
		T* tmp = new T[physicalSize];
		for (int i = 0; i < logicalSize; i++)
		{
			tmp[i] = arr[i];
		}
		delete[]arr;
		arr = tmp;
		tmp = nullptr;
	}
	arr[logicalSize++] = newVal;
	return *this;
}
//------------------------------------------------------------------------------//




#endif // !ARRAY_H_

