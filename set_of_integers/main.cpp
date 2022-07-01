#include<iostream>
#include"SoI.h"

using namespace std;

int main() {

	const int sz = 5;
	unsigned int arr[sz]{ 1,2,3,4,5};
	SoI A(arr, sz);
	cout << A;
	const int sz2 = 5;
	unsigned int arr2[sz2]{ 6,3,8,5,10 };
	SoI B(arr2, sz2);
		SoI C = A + B;
		cout << C;
	return 0;
}