#include "ComplexArray.h"

ComplexArray::ComplexArray()
{
	_size = 0;
	_arr = nullptr;
}

ComplexArray::ComplexArray(int size)
{
	_size = size;
	_arr = new Complex[size];
}

ComplexArray::ComplexArray(const Complex* arr, int size) :_size(size)
{
	_arr = new Complex[size];
	for (int i = 0; i < size; i++)
	{
		_arr[i] = arr[i];
	}
}

ComplexArray::ComplexArray(const ComplexArray& other) :ComplexArray()
{
	*this = other;
}

ComplexArray::~ComplexArray()
{
	if (_arr)
	{
		delete[] _arr;
	}
}

string ComplexArray::toString() const
{
	string str = "ComplexArray[";
	for (int i = 0; i < _size - 1; i++)
	{
		str += _arr[i].toString() + ", ";
	}
	if (_size)
		str += _arr[_size - 1].toString();
	return str + "]";
}

ComplexArray& ComplexArray::operator=(const ComplexArray& other)
{
	this->_size = other._size;
	if (_arr)
	{
		delete[] _arr;
	}
	_arr = new Complex[_size];
	for (int i = 0; i < _size; i++)
	{
		_arr[i] = other._arr[i];
	}
	return (*this);
}

bool ComplexArray::operator==(const ComplexArray& other) const
{
	if (this == &other)
	{
		return true;
	}
	if (this->_size != other._size)
		return false;
	for (int i = 0; i < _size; i++)
	{
		if (this->_arr[i] != other._arr[i])
		{
			return false;
		}
	}
	return true;
}

bool ComplexArray::operator!=(const ComplexArray& other) const
{
	return !this->operator==(other);
}

Complex& ComplexArray::operator[](int index)
{
	if(index < 0)
	{
		index += _size;
	}
	return _arr[index % _size];
}

ComplexArray ComplexArray::operator+(const ComplexArray& other) const
{
	Complex* temp = new Complex[this->_size + other._size];
	int i,index=0;
	for (i = 0; i < this->_size; i++)
	{
		temp[index++] = this->_arr[i];
	}
	for (i = 0; i < other._size; i++)
	{
		temp[index++] = other._arr[i];
	}
	ComplexArray c(temp, this->_size + other._size);
	delete[] temp;
	return c;
}

ComplexArray& ComplexArray::operator+=(const ComplexArray& other)
{
	*this = *this + other;
	return *this;
}

ComplexArray& ComplexArray::operator+=(const Complex& complex)
{
	//temp array with size+1
	Complex* temp = new Complex[_size + 1];

	//copying all current elements
	for (int i = 0; i < _size; i++)
	{
		temp[i] = _arr[i];
	}
	//adding the new element
	temp[_size] = complex;
	//deleting current array
	if (_arr)
		delete[] _arr;
	//replace arr with temp
	_arr = temp;
	//updating the size
	_size++;
	return (*this);
}

Complex ComplexArray::operator!() const
{
	Complex sum;
	for (int i = 0; i < _size; i++)
	{
		sum += _arr[i];
	}
	return sum;
}

ostream& operator<<(ostream& output, const ComplexArray& ComplexArray)
{
	return output << ComplexArray.toString();
}

istream& operator>>(istream& input, ComplexArray& ComplexArray)
{
	for (int i = 0; i < ComplexArray._size; i++)
	{
		cout << "enter complex number:" << i + 1 << "/" << ComplexArray._size;
		input >> ComplexArray._arr[i];
	}
	return input;
}
