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