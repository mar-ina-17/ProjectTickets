#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>

//! this Vector.h is influenced by the implementation of the std::vector at the exercises 
//! credits to: Dimitar Sotirov and Daniel Radev, and also 3rd group in general

template <class T>
class Vector
{
private:
	T* arr;
	size_t size;
	size_t capacity;

	void copy(const Vector<T>&);
	void erase();
	void resize();

public:
	Vector();
	Vector(size_t capacity);
	Vector(const Vector<T>&);
	Vector& operator=(const Vector<T>&);
	~Vector();

	const T& operator[](size_t ) const;
	T& operator[](size_t );

	size_t getSize() const;
	size_t getCapacity() const;

	void push_back(T);//& change

	bool isEmpty () const;

	void printVector() const;

	friend std::istream& operator>>(std::istream& is, Vector<T>& other) 
	{
		for(int i=0; i < other.size; ++i){
			is>>other.arr[i];
		}

		return is;
	}

	friend std::ostream& operator<<(std::ostream& out, const Vector<T>& other) 
	{
		if(other.isEmpty()) 
		{
			std::cout<<"Vector is empty!"<<std::endl;
		}

		for(int i = 0; i < other.size; i++)
		{
			out<<other.arr[i]<<std::endl;
		}
		out<<std::endl;

		return out;
	}
};


template<class T>
void Vector<T>::copy(const Vector<T>& other) {
	this->size = other.size;
	this->capacity = other.capacity;
	
	erase();
	this->arr = new T[this->capacity];
	for (size_t i = 0; i < this->size; ++i) {
		this->arr[i] = other.arr[i];
	}
}

template<class T>
void Vector<T>::erase() {
	delete[] this->arr;
}

template<class T>
void Vector<T>::resize() {
	T* temp = new T[this->capacity * 2];
	this->capacity *= 2;

	for (size_t i = 0; i < this->size; ++i) {
		temp[i] = this->arr[i];
	}
	this->erase();
	this->arr = temp;
}

template<class T>
Vector<T>::Vector() {
	this->capacity = 8;
	this->size = 0;
	this->arr = new T[capacity];
}

template<class T>
Vector<T>::Vector(size_t capacity) 
{
	this->size = 0;
	this->capacity = capacity;
	this->arr = new T[capacity];
}

template<class T>
Vector<T>::Vector(const Vector<T>& other) {
	this->copy(other);
}

template<class T>
Vector<T>& Vector<T>::operator=(const Vector<T>& other) {
	if (this != &other) {
		this->erase();
		this->copy(other);
	}

	return *this;
}

template<class T>
Vector<T>::~Vector() {
	this->erase();
}

template<class T>
const T& Vector<T>::operator[](size_t index) const {
	return this->arr[index];
}

template<class T>
T& Vector<T>::operator[](size_t index) {
	return this->arr[index];
}

template<class T>
size_t Vector<T>::getSize() const {
	return this->size;
}

template<class T>
size_t Vector<T>::getCapacity() const {
	return this->capacity;
}

template<class T>
void Vector<T>::push_back(T element) { //&
	this->size++;
	if (this->size >= this->capacity) {
		this->resize();
	}

	this->arr[this->size - 1] = element;
}


template <class T>
bool Vector<T>::isEmpty() const {
    return !this->size;
}

template<class T>
void Vector<T>::printVector() const {
	std::cout<<"[";
	for(int i = 0; i < this->size; ++i) {
		this->arr[i].print();
	}
	std::cout<<"]"<<std::endl;
}

#endif