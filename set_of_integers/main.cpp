#include<iostream>
#include"SoI.h"

using namespace std;

int main() {

	const int sz = 10;
	unsigned int arr[sz]{ 3,5,3,12,7,8,9,12,4,3 };
	SoI A(arr, sz);
	
	A.print();


	return 0;
}