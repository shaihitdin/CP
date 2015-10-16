#include <bits/stdc++.h>

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)

const int N = 3e5 + 100;

int n;
map <string, int> used[3], banned[3];
string s[3];

int main () {

	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
	
	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	cin >> n;
	forn(i, 1, n) {
		string ban;
		cin >> s[0] >> s[1] >> s[2] >> ban;
		forn(j, 0, 2) {
			if (!used[j][s[j]])
				used[j][s[j]] = 1;         
			if (s[j] == ban)
				banned[j][s[j]] = 1;
			cout << used[j].size() - banned[j].size() << " ";
		}
		cout << "\n";
	}

	
	return 0;
}