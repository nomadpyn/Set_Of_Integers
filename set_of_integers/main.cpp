#include<iostream>
#include"SoI.h"

using namespace std;

int main() {

	const int sz = 5;
	unsigned int arr[sz]{ 1,2,3,4,5};
	SoI A(arr, sz);
	cout << A;
	SoI C{};
	C = A+6;
	cout << C;
	return 0;
}