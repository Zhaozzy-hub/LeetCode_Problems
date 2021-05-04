#include <vector>
#include <iostream>
#include <map>
using namespace std;



int rec_gridTraveler(int m, int n)
{
	int a;
	if (m == 0 or n == 0) {
		return 0;
	}
	if (m == 1 and n == 1) {
		return 1;
	}
	a = rec_gridTraveler(m - 1, n) + rec_gridTraveler(m , n - 1);

	return	a;

}


unsigned long long int dp_gridTraveler(int m, int n, map<pair<int,int>,unsigned long long int> &dict)
{
	pair<int, int> tmp1 = { m,n };
	pair<int, int> tmp2 = { n,m };
	if (m == 0 or n == 0) {
		return unsigned long long int (0);
	}
	if (m == 1 and n == 1) {
		return unsigned long long int(1);
	}
	if (dict.find(tmp1) != dict.end() or dict.find(tmp2) != dict.end())
	{
		return (dict.find(tmp1) != dict.end()) ? dict[tmp1] : dict[tmp2];
	}
	dict[tmp1] = unsigned long long int(dp_gridTraveler(m - 1, n, dict)) + unsigned long long int(dp_gridTraveler(m, n - 1, dict));
	return dict[tmp1];
}

//int main() {
//	map<pair<int, int>, unsigned long long int> dict;
//	cout << rec_gridtraveler(3, 2) << endl;
//	cout << dp_gridtraveler(18, 18, dict) << endl;
//}