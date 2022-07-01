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
	SoI (const unsigned int *arrP, const int szP) : size{ szP } {
		this->arr = new unsigned int[this->size] {};
		for (int i = 0; i < this->size; i++)
			this->arr[i] = arrP[i];
		if (isSoI() == false)
			makeSoI();
	}
	SoI():SoI(3){}
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
	bool isSoI() const;
	void makeSoI();
	void print() const;
	friend ostream& operator << (ostream& ouput, const SoI& arr);
};

