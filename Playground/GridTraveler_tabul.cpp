#include <vector>
#include <iostream>
#include <map>
#include <string>
using namespace std;


unsigned long long int GridTraveler_tab(int n, int m) {
	vector<vector<unsigned long long int>> tab(n + 1, vector<unsigned long long int>(m + 1, 0));
	tab[1][1] = 1;
	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < m + 1; j++) {
			tab[i][j] += tab[i - 1][j] + tab[i][j - 1];
		}
	}

	return tab[n][m];
}



//int  main() {
//	cout << GridTraveler_tab(1, 1) << endl;
//	cout << GridTraveler_tab(2, 3) << endl;
//	cout << GridTraveler_tab(3, 2) << endl;
//	cout << GridTraveler_tab(3, 3) << endl;
//	cout << GridTraveler_tab(18, 18)<< endl;
//}