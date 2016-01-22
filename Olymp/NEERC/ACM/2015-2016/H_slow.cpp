#include <bits/stdc++.h>

using namespace std;

map <int, vector <string> > Map;

const int K = 5, NEED = 6;

int pw[K + 1];

inline void rec (const int &pos, bool flag1, bool flag2, const string &s, int h) {
	if (K - 1 == pos) {
		if (flag1 == 1 && flag2 == 1)
			Map[h].emplace_back (s);
		return;
	}

	for (char i = 'a'; i <= 'z'; ++i)
		rec (pos + 1, flag1 | 1, flag2, s + i, h + (i * pw[K - pos - 1]));
	
	for (char i = 'A'; i <= 'Z'; ++i)
		rec (pos + 1, flag1, flag2 | 1, s + i, h + (i * pw[K - pos - 1]));

}

int main () {

	freopen ("out", "w", stdout);

	pw[0] = 1;
	
	for (int i = 1; i <= K; ++i)
		pw[i] = pw[i - 1] * 31;
	
	rec (0, 0, 0, "", 0);

	for (auto it : Map) {
		if (it.second.size () > NEED) {
			cout << "{";
			for (auto it2 : it.second)
				cout << char (34) << it2 << char (34) << ", ";
			cout << "}";
			cout << "\n";
		}
	}
	
	return 0;
}