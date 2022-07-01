#pragma once
#include<iostream>

using namespace std;

class SoI
{
private:
	int size;
	unsigned int* arr;
public:
	SoI(const int szP) :size{ szP } {
		this->arr = new unsigned int[this->size] {};
	}
	SoI(const unsigned int* arrP, const int szP) : size{ szP } {
		this->arr = new unsigned int[this->size]{};
		for (int i = 0; i < this->size; i++)
			this->arr[i] = arrP[i];
		if (isSoI() == false)
			makeSoI();
	}
	SoI() :SoI(3) {}
	~SoI() {
		delete[] this->arr;
	}
	SoI(const SoI& other) : size{ other.size } {
		if (this->arr != nullptr)
			delete[] this->arr;
		this->arr = new unsigned int[this->size];
		for (int i = 0; i < this->size; i++)
			this->arr[i] = other.arr[i];
	}
	void print() const;
	bool isSoI() const;
	void makeSoI();
	bool isValueInArr(unsigned int) const;
	int getSize() const;
	SoI& operator=(const SoI& other);
	friend ostream& operator << (ostream& ouput, const SoI& obj);
	friend istream& operator >> (istream& input, SoI& obj);
	SoI operator+=(unsigned int);
	friend SoI operator+(SoI& obj, unsigned int);
	unsigned int& operator[](int);
};
