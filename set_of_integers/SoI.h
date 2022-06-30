#pragma once
class SoI
{
private:
	int size;
	unsigned int* arr;
public:
	SoI(const int szP) :size{ szP } {
		this->arr = new unsigned int[this->size] {};
		cout << "You create array with " << this->size << " elements.\n";
		cout << "To make Set of Integers you need fill this array\n";
	}
	SoI (const unsigned int *arrP, const int szP) : size{ szP } {
		this->arr = new unsigned int[this->size] {};
		for (int i = 0; i < this->size; i++)
			this->arr[i] = arrP[i];
		cout << "You create array with " << this->size << " elements.\n";
		cout << "To make Set of Integers we need check this array for coincidence.\n";
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
};

