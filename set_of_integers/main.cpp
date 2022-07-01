#include<iostream>
#include"SoI.h"

using namespace std;

int main() {

	const int sz = 10;
	unsigned int arr[sz]{ 3,5,3,5,3,2,1,2,5,3 };
	SoI A(arr, sz);
	SoI B(5);
	cin >> B;
	cout << B;

	return 0;
}