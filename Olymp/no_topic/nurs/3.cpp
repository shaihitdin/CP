#include <iostream>
#include <algorithm>

using namespace std;

int a[1000][1000];

int main () {

	setlocale(LC_ALL,"Russian");

	cout << "������� ���������� ����� �������: ";

	int n;
	cin >> n;

	cout << "������� ���������� �������� �������: ";

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
	
	
	cout << "���� ������� = " << ans;
	return 0;
}