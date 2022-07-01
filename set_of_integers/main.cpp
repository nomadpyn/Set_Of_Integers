#include<iostream>
#include"SoI.h"

using namespace std;

int main() {

	const int sz = 5;
	unsigned int arr[sz]{ 1,2,3,4,5};
	SoI A(arr, sz);
	cout << A;
	A += 5;
	cout << A;
	return 0;
}