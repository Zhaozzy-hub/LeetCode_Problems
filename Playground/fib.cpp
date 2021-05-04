#include <iostream>
using namespace std;


int rec_fib(int n) {
	int a;
	if (n == 1 or n == 2) {
		return 1;
	}
	a = rec_fib(n - 1) + rec_fib(n - 2);
	return a;

}



unsigned long long int dp_fib(int n) {
	unsigned long long int arr[2] = {1, 1};
	if (n <= 2)
	{
		return 1;
	}
	int i;
	for (i = 2; i < n; i++)
	{
		unsigned long long int tmp = arr[0];
		arr[0] = arr[1];
		arr[1] = tmp + arr[0];
	}

	return arr[1];
}






//int main() {
//	
//	cout << rec_fib(3) << endl;
//	cout << dp_fib(50) << endl;
//}