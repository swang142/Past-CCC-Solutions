#include <iostream>
using namespace std;


bool opensSafe(int dig1, int dig2, int dig3, int dig4) {
	int code1 = 2, code2 = 4, code3 = 7, code4 = 1;
	return dig1 == code1 && dig2 == code2 && dig3 == code3 && dig4 == code4;
}


int main() {
	bool codeFound = false;
	for (int firstDig = 0; firstDig <= 9; firstDig++) {
		for (int secondDig = 0; secondDig <= 9; secondDig++) {
			for (int thirdDig = 0; thirdDig <= 9; thirdDig++) {
				for (int fourthDig = 0; fourthDig <= 9; fourthDig++) {
					if (opensSafe(firstDig, secondDig, thirdDig,fourthDig)) {
					  cout << "Code is " << firstDig << secondDig<< thirdDig <<fourthDig << '\n';
                        return 0;
	
					}
				}
			}
	
		}
	}
}
