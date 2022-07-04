#include "SoI.h"
#include<iostream>

using namespace std;
// метод вывода информации об объекте на экран
void SoI::print() const {
	for (int i = 0; i < this->size; i++)
		cout << this->arr[i] << " | ";
	cout << endl;
}
// метод проверки созданного объекта, является ли он множеством целых чисел
bool SoI::isSoI() const {
	for (int i = 1; i < this->size; i++) {
		for (int y = 0; y < i; y++) {
			if (this->arr[y] == this->arr[i])
				return false;				
		}
	}
	return true;
}
// метод, который превращает обычный массив в множество целых чисел
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
// метод проверки вхождения числа в множество
bool SoI::isValueInArr(unsigned int value) const {
	for (int i = 0; i < this->size; i++) {
		if (this->arr[i] == value)
			return true;
	}
	return false;
}
// геттер для размера множества
int SoI::getSize() const {
	return this->size;
}
// метод получения значения из множества по индексу
unsigned int& SoI::operator[](int value) const  {
	return this->arr[value];
}
// перегрузка оператора присваивания
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
// перегрузка оператора вывода 
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
// перегрузка оператора ввода
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
// перегрузка оператора += (прибавления элемента к множеству)
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
// перегрузка оператора + (объединение двух множеств)
SoI operator+(SoI& obj1,SoI& obj2) {
	SoI tmp{ obj1.size + obj2.size};
	for (int i = 0; i < tmp.size/2; i++) {
		tmp.arr[i] = obj1.arr[i];
		tmp.arr[i + obj1.size] = obj2.arr[i];
	}
	tmp.makeSoI();
	return tmp;
}
// перегрузка оператора -= (удаление нескольких значений из множества)
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
// перегрузка опертора - (разность множеств)
SoI operator-(const SoI& obj1,const SoI& obj2) {
	SoI tmp{ obj1.size };
	for (int i = 0; i < tmp.size;i++) {
		tmp.arr[i] = obj1.arr[i];
		for (int y = 0; y < obj2.size; y++) {
			if (obj1.arr[i] == obj2.arr[y])
				tmp.arr[i] = 0;
		}
			
	}
	int nw_sz = 0;
	unsigned int * t_arr = new unsigned int[obj1.size];
	for (int i = 0; i < obj1.size; i++) {
		if (tmp.arr[i] != 0) {
			t_arr[nw_sz] = tmp.arr[i];
			nw_sz++;
		}
	}
	delete [] tmp.arr;
	tmp.size = nw_sz;
	tmp.arr = new unsigned int[nw_sz];
	for (int i = 0; i < nw_sz; i++)
		tmp.arr[i] = t_arr[i];
	delete[] t_arr;
	return tmp;
}
// перегрузка оператора * (пересечение множеств)
SoI operator * (const SoI& obj1, const SoI& obj2) {
	SoI tmp{ obj1.size + obj2.size };
	int nw_sz = 0;
	bool find = true;
	for (int i = 0; i < obj1.size; i++) {
		find = true;
		for (int y = 0; y < obj2.size; y++) {
			if (obj2.arr[y] == obj1.arr[i])
				find = false;
		}
		if (find == false) {
			tmp.arr[nw_sz]=obj1.arr[i];
			nw_sz++;
		}
	}
	unsigned int* t_arr = new unsigned int[nw_sz];
	for (int i = 0; i < nw_sz; i++) {
		t_arr[i] = tmp.arr[i];
	}
	delete[] tmp.arr;
	tmp.size = nw_sz;
	tmp.arr = new unsigned int[nw_sz];
	for (int i = 0; i < nw_sz; i++) {
		tmp.arr[i] = t_arr[i];
	}
	delete[] t_arr;
	return tmp;
}
// перегрузка опертора сравнения двух множеств
bool operator == (const SoI& obj1, const SoI& obj2) {
	if (obj1.size != obj2.size)
		return false;
	for (int i = 1; i < obj1.size; i++) {
		if (obj1.arr[i] != obj2.arr[i])
			return false;
	}
	return true;
}