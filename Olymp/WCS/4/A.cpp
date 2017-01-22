#include <bits/stdc++.h>

using namespace std;

vector <int> edges[8][8];
pair <int, int> pos[8][8];

vector <pair <int, int> > ans_pos, ans_edges;

inline void construct (int psx, int vertexes, int done) {
	for (int i = 1; i <= vertexes; ++i)
		ans_pos.emplace_back (make_pair (psx + pos[vertexes][i].first, pos[vertexes][i].second));
	for (int i = 1; i <= vertexes; ++i) {
		for (auto it : edges[vertexes][i]) {
			ans_edges.emplace_back (make_pair (i + done, done + it));
		}
	}
}

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	pos[4][1] = make_pair (0, 0);
	pos[4][2] = make_pair (2, 0);
	pos[4][3] = make_pair (1, 1);
	pos[4][4] = make_pair (1, 2);
	pos[3][1] = make_pair (0, 0);
	pos[3][2] = make_pair (2, 0);
	pos[3][3] = make_pair (1, 1);
	pos[2][1] = make_pair (0, 0);
	pos[2][2] = make_pair (1, 1);
	pos[1][1] = make_pair (0, 0);
	pos[5][1] = make_pair (0, 0);
	pos[5][2] = make_pair (2, 0);
	pos[5][3] = make_pair (1, 1);
	pos[5][4] = make_pair (0, 2);
	pos[5][5] = make_pair (2, 2);
	pos[6][1] = make_pair (0, 0);
	pos[6][2] = make_pair (3, 0);
	pos[6][3] = make_pair (1, 1);
	pos[6][4] = make_pair (2, 1);
	pos[6][5] = make_pair (0, 2);
	pos[6][6] = make_pair (3, 3);

	edges[3][1].emplace_back (2);
	edges[3][1].emplace_back (3);
	edges[3][2].emplace_back (3);

	edges[4][1].emplace_back (2);
	edges[4][1].emplace_back (3);
	edges[4][1].emplace_back (4);
	edges[4][2].emplace_back (3);
	edges[4][2].emplace_back (4);
	edges[4][3].emplace_back (4);

	edges[5][1].emplace_back (2);
	edges[5][1].emplace_back (4);
	edges[5][1].emplace_back (3);
	edges[5][2].emplace_back (5);
	edges[5][2].emplace_back (3);
	edges[5][3].emplace_back (5);
	edges[5][4].emplace_back (5);

	edges[6][1].emplace_back (2);
	edges[6][1].emplace_back (5);
	edges[6][1].emplace_back (3);
	edges[6][2].emplace_back (4);
	edges[6][2].emplace_back (6);
	edges[6][3].emplace_back (5);
	edges[6][3].emplace_back (4);
	edges[6][4].emplace_back (6);
	edges[6][5].emplace_back (6);
	
	int n;
	
	cin >> n;

	int now = 0, psx = 0;
	while (n >= 8) {
		construct (psx, 4, now);
		now += 4;
		psx += 20;
		n -= 4;
	}
	
	if (n == 7) {
		construct (psx, 6, now);
		now += 6;
		psx += 20;
		construct (psx, 1, now);
	} else {
		construct (psx, n, now);
	}
	
	for (auto it : ans_pos) {
		cout << it.first << " " << it.second << "\n";
	}
	cout << ans_edges.size () << "\n";
	for (auto it : ans_edges) {
		cout << it.first << " " << it.second << "\n";
	}
	return 0;
}