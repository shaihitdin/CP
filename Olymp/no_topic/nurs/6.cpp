#include <iostream>
#include <string>
#include <wchar.h>

using namespace std;

struct person {
	int age;
	wstring name;
	wstring surname;
	person () {
	
	}
	person (wstring _name, wstring _surname, int _age) {
		age = _age;
		name = _name;
		surname = _surname;	
	}
};

person a[10];

int main () {

	setlocale(LC_ALL,"Russian");

	cout << "������� ������: ";

	string s;

	int size = 0;

	while (cin >> s) {
		wstring name, surname;
		int age;
		cin >> name;
		cin >> s;
		cin >> surname;
		cin >> s;
		cin >> age;
		cin >> s;
		a[size++] = person (name, surname, age);
	}
	
	int ans = 0;

	for (int i = 1; i < size; ++i) {
		if (a[i].age > a[ans].age || (a[i].age == a[ans].age && a[i].name > a[ans].name))
			ans = i;
	}
	
	cout << "��������� -  ����� ������� ������� � ����� ������� ������:" << endl;

	cout << "���: " << a[ans].name << "\n";		
	cout << "�������: " << a[ans].surname << "\n";		
	cout << "�������: " << a[ans].age << "\n";		
	
	return 0;
}