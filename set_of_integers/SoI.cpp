#include "SoI.h"
#include<iostream>

using namespace std;

void SoI::print() const {
	for (int i = 0; i < this->size; i++)
		cout << this->arr[i] << " | ";
	cout << endl;
}
bool SoI::isSoI() const {
	for (int i = 1; i < this->size; i++) {
		for (int y = 0; y < i; y++) {
			if (this->arr[y] == this->arr[i])
				return false;				
		}
	}
	return true;
}

void SoI::makeSoI() {
	while (isSoI()==false) {
		
		for (int i = 1; i < this->size; i++) {
			for (int y = 0; y < i; y++) {
				if (this->arr[y] == this->arr[i]) {
					unsigned int* arrN = new unsigned int[this->size - 1];
					for (int x = 0; x < i; x++)
						arrN[x] = this->arr[x];
					for (int x = i; x < size - 1; x++)
						arrN[x] = this->arr[x + 1];
					delete[] this->arr;
					this->size--;
					this->arr = new unsigned int[this->size];
					for (int u = 0; u < size ;u++)
						this->arr[u] = arrN[u];
					delete[] arrN;
					break;
				}
			}
		}
	}
}

bool SoI::isValueInArr(unsigned int value) const {
	for (int i = 0; i < this->size; i++) {
		if (this->arr[i] == value)
			return true;
	}
	return false;
}

int SoI::getSize() const {
	return this->size;
}

unsigned int& SoI::operator[](int value) {
	return this->arr[value];
}

SoI& SoI::operator=(const SoI& other) {
	if (this == &other)
		return *this;
	delete[] this->arr;
	this->size = other.size;
	this->arr = new unsigned int[this->size];
	for (int i = 0; i < this->size; i++)
		this->arr[i] = other.arr[i];
	return *this;
}

ostream& operator<<(ostream& output, const SoI& obj){
	cout << "Set of Integers = ";
	for (int i = 0; i < obj.size; i++) {
		output << obj.arr[i];
		if (i < obj.size - 1)
			output << "-";
	}
	cout << endl;
	return output;
}
istream& operator>>(istream& input, SoI& obj) {
	cout << "Enter " << obj.size << " numbers in arr from 1 to > \n";
	for (int i = 0; i < obj.size; i++)
		input >> obj.arr[i];
	if (obj.isSoI())
		return input;
	else {
		obj.makeSoI();
	}

}
SoI operator+(SoI& obj, unsigned int value)
{
	return SoI(obj+=value);
}
SoI SoI::operator+=(unsigned int value) {
	if (!isValueInArr(value)) {
		unsigned int* tmp = new unsigned int[this->size + 1];
		for (int i = 0; i < this->size; i++)
			tmp[i] = this->arr[i];
		tmp[this->size] = value;
		delete[] this->arr;
		this->size++;
		this->arr = new unsigned int[this->size];
		for (int i = 0; i < this->size; i++)
			this->arr[i] = tmp[i];
		delete[]tmp;
	}
	return *this;
}

SoI operator+(SoI& obj1, SoI& obj2) {
	SoI tmp{ obj1.size + obj2.size};
	for (int i = 0; i < tmp.size/2; i++) {
		tmp.arr[i] = obj1.arr[i];
		tmp.arr[i + obj1.size] = obj2.arr[i];
	}
	tmp.makeSoI();
	return tmp;

}

SoI SoI::operator-=(unsigned int value) {
	if(value < this->size){
		unsigned int* tmp = new unsigned int[this->size - value];
		for (int i = 0; i < this->size-value; i++)
			tmp[i] = this->arr[i];
		delete[] this->arr;
		this->size-=value;
		this->arr = new unsigned int[this->size];
		for (int i = 0; i < this->size; i++)
			this->arr[i] = tmp[i];
		delete[]tmp;
	}
	return *this;
}

SoI operator-(SoI& obj1, SoI& obj2) {
	SoI tmp{ obj1.size };
	for (int i = 0; i < tmp.size;i++) {
		tmp.arr[i] = obj1.arr[i];
		for (int y = 0; y < obj2.size; y++) {
			if (obj1.arr[i] == obj2.arr[y])
				tmp.arr[i] = 0;
		}
			
	}
	return tmp;
}