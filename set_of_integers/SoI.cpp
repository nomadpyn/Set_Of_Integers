#include "SoI.h"
#include<iostream>

using namespace std;

bool SoI::isSoI() const {
	for (int i = 1; i < this->size; i++) {
		for (int y = 0; y < i; y++) {
			if (this->arr[y] == this->arr[i])
				return false;				
		}
	}
	return true;
}
