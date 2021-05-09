#include <vector>
#include <iostream>
using namespace std;


int knapsack(vector<int> v, vector<int> w, int C) {
	int n = v.size() + 1;
	int m = C + 1;
	vector<vector<int>> tab(n, vector<int>(m));
	for (int i = 0; i <= v.size(); i++) {
		for (int j = 0; j <= C; j++) {
			if (i == 0 || j == 0) {
				tab[i][j] = 0;
				cout << tab[i][j] << " ";
			}
			else if (w[i-1] <= j) {
				tab[i][j] = max(tab[i-1][j],tab[i-1][j-w[i-1]]+v[i-1]);
				cout << tab[i][j] << " ";
			}
			else {
				tab[i][j] = tab[i - 1][j];
				cout << tab[i][j] << " ";
			}
		}
		cout << endl;
	}
	return tab[v.size()][C];

}






//int main() {
//	int c = 5;
//	vector<int> v = { 10,20,25,9 };
//	vector<int> w = { 3,4,5,1 };
//	cout << knapsack(v, w, c) << endl;
//	
//}