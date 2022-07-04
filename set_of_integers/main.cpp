#include<iostream>
#include"SoI.h"

using namespace std;
// функция информирования о равенстве множеств
void equal(const SoI& A, const SoI& B) {
	if (A == B)
		cout << "SoI is equal\n";
	else
		cout << "SoI isnt equal\n";
}

int main() {

	const int sz = 5;
	unsigned int arr[sz]{ 1,2,3,4,5};
	SoI A(arr, sz);
	cout << "A " << A;
	const int sz2 = 5;
	unsigned int arr2[sz2]{6,5,8,1,9};
	SoI B(arr2, sz2);
	cout << "B " << B;
	SoI C = A + B;
	cout <<"A + B " << C;
	SoI D = A - B;
	cout << "A - B " << D;
	SoI E = A * B;
	cout << "A * B " << E;
	cout << "A and B ";
	equal(A, B);
	return 0;
}