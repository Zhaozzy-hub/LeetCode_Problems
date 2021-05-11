#include <vector>
#include <iostream>
using namespace std;


bool solve(int maxChoosableInteger, int desiredTotal, int k, int it ) {
	if (k == 1 && desiredTotal == 0) {
		return true;
	}
	if ((desiredTotal <= 0 and k%2 != 0) || (desiredTotal <= maxChoosableInteger and k%2 == 0)) {
		return false;
	}
	if ((desiredTotal <= 0 and k % 2 == 0) || (desiredTotal <= maxChoosableInteger and k % 2 != 0)) {
		return true;
	}
	bool tmp = false;
	for (int i = it; i <= maxChoosableInteger; i++) {
		bool a, b;
		if (k % 2 != 0) {
			a = solve(maxChoosableInteger, desiredTotal - i,k+1,i+1);
			tmp = tmp || a;
		}
		if (k % 2 == 0) {
			tmp = true;
			b = solve(maxChoosableInteger, desiredTotal - i,k+1,i+1);
			tmp = tmp and b;
		}
	}
	
	return tmp;

}



//int main() {
//	cout << solve(10, 100,1,1) << endl;
//}