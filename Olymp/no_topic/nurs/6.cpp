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

	cout << "Входные данные: ";

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
	
	cout << "Результат -  самый старший человек с самым длинным именем:" << endl;

	cout << "Имя: " << a[ans].name << "\n";		
	cout << "Фамилия: " << a[ans].surname << "\n";		
	cout << "Возраст: " << a[ans].age << "\n";		
	
	return 0;
}