#include <iostream>

using namespace std;

void func (int a[], int &n, int x) {
	int size = 0;
	for (int i = 0; i < n; ++i)
		if (i != x)
			a[size++] = a[i];
	--n;
}

int main () {

	setlocale(LC_ALL,"Russian");

	cout << "������� ���������� ��������� �������: ";

	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	cout << "������� ����� �������� �������, ������� ���������� �������: ";
	int x;
	cin >> x;

	func (a, n, x);


	cout << "���������: ";

	for (int i = 0; i < n; ++i)
		cout << a[i] << " ";
			
	return 0;
}