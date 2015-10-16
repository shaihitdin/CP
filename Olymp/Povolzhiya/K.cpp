#include <bits/stdc++.h>

using namespace std;

bitset <8> c[11];

string a[11];
char b[11][11][11];
bitset <8> cc[11];

inline bitset <8> restore_image (const int &i) {
	bitset <8> res;
	res[1] = b[i][1][2] == 'x';
	res[2] = b[i][2][1] == 'x';
	res[3] = b[i][2][5] == 'x';
	res[4] = b[i][5][2] == 'x';
	res[5] = b[i][6][1] == 'x';
	res[6] = b[i][6][5] == 'x';
	res[7] = b[i][9][2] == 'x';
	return res;
}


int main () {

	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);

	
	c[0][1] = 1;
	c[0][2] = 1;
	c[0][3] = 1;
	c[0][4] = 0;
	c[0][5] = 1;
	c[0][6] = 1;
	c[0][7] = 1;


	c[1][1] = 0;
	c[1][2] = 0;
	c[1][3] = 1;
	c[1][4] = 0;
	c[1][5] = 0;
	c[1][6] = 1;
	c[1][7] = 0;

	
	c[2][1] = 1;
	c[2][2] = 0;
	c[2][3] = 1;
	c[2][4] = 1;
	c[2][5] = 1;
	c[2][6] = 0;
	c[2][7] = 1;


	c[3][1] = 1;
	c[3][2] = 0;
	c[3][3] = 1;
	c[3][4] = 1;
	c[3][5] = 0;
	c[3][6] = 1;
	c[3][7] = 1;


	c[4][1] = 0;
	c[4][2] = 1;
	c[4][3] = 1;
	c[4][4] = 1;
	c[4][5] = 0;
	c[4][6] = 1;
	c[4][7] = 0;


	c[5][1] = 1;
	c[5][2] = 1;
	c[5][3] = 0;
	c[5][4] = 1;
	c[5][5] = 0;
	c[5][6] = 1;
	c[5][7] = 1;

	
	c[6][1] = 1;
	c[6][2] = 1;
	c[6][3] = 0;
	c[6][4] = 1;
	c[6][5] = 1;
	c[6][6] = 1;
	c[6][7] = 1;

	
	c[7][1] = 1;
	c[7][2] = 0;
	c[7][3] = 1;
	c[7][4] = 0;
	c[7][5] = 0;
	c[7][6] = 1;
	c[7][7] = 0;

	
	c[8][1] = 1;
	c[8][2] = 1;
	c[8][3] = 1;
	c[8][4] = 1;
	c[8][5] = 1;
	c[8][6] = 1;
	c[8][7] = 1;


	c[9][1] = 1;
	c[9][2] = 1;
	c[9][3] = 1;
	c[9][4] = 1;
	c[9][5] = 0;
	c[9][6] = 1;
	c[9][7] = 1;

	for (int i = 1; i <= 9; ++i) {
		cin >> a[i];
		a[i] = "#" + a[i];
	}	

	for (int i = 0; i <= 9; ++i) {
		int s_p = i * 6;
		for (int j = 1; j <= 9; ++j) {
			for (int k = 1; k <= 5; ++k) {
				b[i][j][k] = a[j][s_p + k];
			}
		}
	}
	
	for (int i = 0; i <= 9; ++i) {
		cc[i] = restore_image (i);
	}
	
	int perm[11];
	
	for (int i = 0; i <= 9; ++i)
		perm[i] = i;
	
	int known[10];
	
	for (;;) {
	
		for (int i = 1; i <= 7; ++i)
			known[i] = -1;
		bool flag = 0;
		for (int i = 0; i <= 9; ++i) {
			for (int j = 1; j <= 7; ++j) {
				if (c[i][j] == 0) {
					if (cc[perm[i]][j] == 0) {
						if (known[j] == -1 || known[j] == 0) {
							continue;
						} else {             
							flag = 1;
						}
					} else {
						if (known[j] == -1 || known[j] == 1) {
							known[j] = 1;
						} else {
							flag = 1;
						}
					}
				} else {
					if (cc[perm[i]][j] == 1) {
						if (known[j] == -1 || known[j] == 1) {
							continue;
						} else {
							flag = 1;
						}
					} else {
						if (known[j] == -1 || known[j] == 0) {
							known[j] = 0;
						} else {
							flag = 1;
						}
					}
				}
			}
		}
		
		if (!flag) {
			for (int i = 1; i <= 7; ++i) {
				if (known[i] == -1) {
					cout << 0 << " ";
				} else if (known[i] == 0) {
					cout << -1 << " ";
				} else if (known[i] == 1) {
					cout << 1 << " ";
				}
			}
			return 0;
		}
		
		if (!next_permutation (perm, perm + 10))
			break;
	}
	
	assert (0);
	
	return 0;
}