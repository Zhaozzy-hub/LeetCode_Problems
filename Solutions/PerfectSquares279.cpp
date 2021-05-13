#include <vector>
#include <iostream>
#include <map>
using namespace std;



int pfs(int  n) {
	vector<int> tab(n+1, 1);
	tab[0] = 0;
	for (int i = 1; i <= n; i++) {
		if (int(sqrt(i))* int(sqrt(i)) == i) {
			tab[i] = 1;
		}
		else {
			int tmp = INT_MAX;
			for (int j = 1; j*j <= i; j++) {
				tmp = min((tab[i%(j*j)] + i/(j*j)), tmp);
			}
			tab[i] = tmp;
		}
	}
	return tab[n];
}


//int main(){
//	cout << pfs(4560) << endl;
//}
