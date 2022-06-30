#pragma once
class SoI
{
private:
	int size;
	unsigned int* arr;
public:
	SoI(const int szP) :size{ szP } {
		arr = new unsigned int[size] {};
		cout << "You create array with " << size << " elements.\n";
		cout << "To make Set of Integers you need fill this array\n";
	}
	SoI (const unsigned int *arrP, const int szP) : size{ szP } {
		arr = new unsigned int[size] {};
		for (int i = 0; i < size; i++)
			arr[i] = arrP[i];
		cout << "You create array with " << size << " elements.\n";
		cout << "To make Set of Integers we need check this array for coincidence.\n";
	}
};

