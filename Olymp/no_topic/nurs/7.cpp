#include <iostream>
#include <string>

using namespace std;

int main () {

	setlocale(LC_ALL,"Russian");
	
	string s;
	string a[1010];
	int size = 0;
	cout << "¬ведите текст:" << endl;
	string x;
	getline (cin, x);
	
	while (cin >> s) {
		string t;
		for (int i = 0; i < s.size (); ++i) {
			if ('a' <= s[i] && s[i] <= 'z')
				s[i] -= ('a' - 'A');
			if ('A' <= s[i] && s[i] <= 'Z') {
				t += s[i];
			}
		}
		a[size++] = t;
	}

	int ans = 0;
	string ans2;
	for (int i = 0; i < size; ++i) {
		int res = 0;
		for (int j = 0; j < size; ++j) {
			if (a[i] == a[j]) {
				++res;
			}
		}
		if (res > ans) {
			ans = res;
			ans2 = a[i];
		}
	}
	
	cout << "—амое встречающеес€ слово в тексте: " << ans2;

	return 0;
}