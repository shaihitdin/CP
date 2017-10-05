#include <iostream>
#include <algorithm>

using namespace std;

int a[1000][1000];

int main () {

	setlocale(LC_ALL,"Russian");

	cout << "¬ведите количество строк матрицы: ";

	int n;
	cin >> n;

	cout << "¬ведите количество столбцов матрицы: ";

	int m;
	cin >> m;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> a[i][j];
		}
	}

	
	int ans = 0;

	for (int i = 0; i < min (m, n); ++i)
		ans += a[i][i];
	
	
	cout << "—лед матрицы = " << ans;
	return 0;
}