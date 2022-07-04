#pragma once
#include<iostream>

using namespace std;
// класс SoI (Set of Integers)
class SoI 
{
private:
	// поле класса для хранения размера множества чисел
	int size;
	// поле класса с динамической память под числа
	unsigned int* arr;	
public:
	// конструкторы с параметрами
	SoI(const int szP) :size{ szP }{
		this->arr = new unsigned int[this->size] {};
	}
	SoI(const unsigned int* arrP, const int szP) : size{ szP } {
		this->arr = new unsigned int[this->size]{};
		for (int i = 0; i < this->size; i++)
			this->arr[i] = arrP[i];
		if (isSoI() == false)
			makeSoI();
	}
	// конструктор по умолчанию
	SoI() :SoI(3) {}
	// декструктор 
	~SoI() {
		delete[] this->arr;
	}
	// конструктор копирования
	SoI(const SoI& other) : size{ other.size } {
		if (this->arr != nullptr)
			delete[] this->arr;
		this->arr = new unsigned int[this->size];
		for (int i = 0; i < this->size; i++)
			this->arr[i] = other.arr[i];
	}
	// описание методов и дружественных функции класса
	void print() const;
	bool isSoI() const;
	void makeSoI();
	bool isValueInArr(unsigned int) const;
	int getSize() const;
	unsigned int& operator[](int) const;
	SoI& operator=(const SoI& other);
	friend ostream& operator << (ostream& ouput, const SoI& obj);
	friend istream& operator >> (istream& input, SoI& obj);
	SoI operator+=(unsigned int);
	friend SoI operator+(SoI& obj1, SoI& obj2);
	SoI operator-=(unsigned int);
	friend SoI operator-(const SoI& obj1, const SoI& obj2);
	friend SoI operator*(const SoI& obj1, const SoI& obj2);
	friend bool operator == (const SoI& obj1, const SoI& obj2);
};
