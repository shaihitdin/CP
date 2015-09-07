#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
char a[51][51];
vector <pair <int,int>> ans;
#define mkp make_pair
#define F first
#define S second
int n, m;
int main () {
	freopen ("crosswords.in", "r", stdin);
	freopen ("crosswords.out", "w", stdout);
	scanf ("%d%d\n", &n, &m);
	for (int i = 1; i <= n; ++i) {		
		for (int j = 1; j <= m; ++j) {
			a[i][j] = getchar();
		}
		getchar();
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (a[i][j] == '#')
				continue;
			if ( (j == 1 || a[i][j - 1] == '#') && (j + 2 <= m && a[i][j + 1] == '.' && a[i][j + 2] == '.')) {
				ans.push_back (mkp (i, j));
			}
			else if ( (i == 1 || a[i - 1][j] == '#') && (i + 2 <= n && a[i + 1][j] == '.' && a[i + 2][j] == '.')){
				ans.push_back (mkp (i, j));			
			}
		}
	}
	printf ("%d\n", ans.size() );
	for (auto x : ans) {
		printf ("%d %d\n", x.F, x.S);
	}
	return 0;
}