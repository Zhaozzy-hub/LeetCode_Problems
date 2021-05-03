#include <vector>
#include <iostream>
using namespace std;


int fbi(int n) {
	int a;
	if (n == 1 or n == 2) {
		return 1;
	}
	a = fbi(n - 1) + fbi(n - 2);
	return a;

}

int main() {

	cout << fbi(3) << endl;
}