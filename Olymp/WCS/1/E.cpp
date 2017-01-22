#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int oo = 1e9, bpr = 1e9 + 7, N = 1e5 + 100;

#define int ll

struct pawn {
	int id, x, y, dist;
};

inline bool operator < (const pawn &cx, const pawn &cy) {
	return cx.dist < cy.dist;
}

map <int, int> lst_diag1, lst_diag2, lst_ver, lst_hor;
int d[N], p[N], p2[N];
vector <pawn> calc_way;

inline int diag1 (int x, int y) {
	return (x - (-oo)) + y;
}

inline int diag2 (int x, int y) {
	return x + (oo - y);
}

inline void Try (int to, int from) {
	if (d[from] + 1 > d[to]) {
		d[to] = d[from] + 1;
		p[to] = from;
	}
}
int n;

int cnt;
vector <pawn> cc[N];
vector <int> pref_pos[N], suff_pos[N], pref[N], suff[N];
int num[N];
int pos_in_cc[N];
vector <int> old_to_p[N], old_to_s[N];

main () {

	#ifdef UNBROKEN
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);
	
	cin >> n;

	for (int i = 1; i <= n; ++i) {
		int x, y;
		cin >> x >> y;
		calc_way.push_back ({i, x, y, y});
	}	
	
	calc_way.push_back ({0, 0, 0, 0});
	
	for (int i = 1; i <= n; ++i)
		d[i] = -oo;
	d[0] = 0;
		
	sort (calc_way.begin (), calc_way.end ());
	
	int calced_y = 0;
	
	for (int i = 0; i < calc_way.size (); ++i) {
		auto pw = calc_way[i];
		if (lst_diag1.count (diag1 (pw.x, pw.y))) {
			int id = lst_diag1[diag1 (pw.x, pw.y)];
			Try (pw.id, id);
		}
		if (lst_diag2.count (diag2 (pw.x, pw.y))) {
			int id = lst_diag2[diag2 (pw.x, pw.y)];
			Try (pw.id, id);
		}
		if (lst_ver.count (pw.x)) {
			int id = lst_ver[pw.x];
			Try (pw.id, id);
		}
		lst_diag1[diag1 (pw.x, pw.y)] = pw.id;
		lst_diag2[diag2 (pw.x, pw.y)] = pw.id;
		lst_ver[pw.x] = pw.id;
		if (i + 1 == calc_way.size () || (calc_way[i + 1].y != calc_way[calced_y].y)) {
			if (i == calced_y) {
				++calced_y;
				continue;
			}
			++cnt;
			for (int j = calced_y; j <= i; ++j) {
				cc[cnt].push_back ({calc_way[j].id, calc_way[j].x, calc_way[j].y, calc_way[j].x});
				num[calc_way[j].id] = cnt;
			}						

			sort (cc[cnt].begin (), cc[cnt].end ());
			
			for (int j = 0; j < cc[cnt].size (); ++j) {
				pos_in_cc[cc[cnt][j].id] = j;
			}

			pref_pos[cnt].resize (cc[cnt].size ());
			pref[cnt].resize (cc[cnt].size ());
			old_to_p[cnt].resize (cc[cnt].size ());
			pref_pos[cnt][0] = 0;
			pref[cnt][0] = d[cc[cnt][0].id];
			old_to_p[cnt][0] = p[cc[cnt][0].id];

			for (int j = 1; j < cc[cnt].size (); ++j) {
				if (pref[cnt][j - 1] + 1 < d[cc[cnt][j].id] + j) {
					pref[cnt][j] = d[cc[cnt][j].id] + j;
					pref_pos[cnt][j] = j;
					old_to_p[cnt][j] = p[cc[cnt][j].id];
				} else {
					pref[cnt][j] = pref[cnt][j - 1] + 1;
					pref_pos[cnt][j] = pref_pos[cnt][j - 1];
					old_to_p[cnt][j] = old_to_p[cnt][j - 1];
				}
			}

			suff_pos[cnt].resize (cc[cnt].size ());
			suff[cnt].resize (cc[cnt].size ());
			old_to_s[cnt].resize (cc[cnt].size ());			

			int len = cc[cnt].size ();
			
			suff[cnt][len - 1] = d[cc[cnt][len - 1].id];
			suff_pos[cnt][len - 1] = len - 1;
			old_to_s[cnt][0] = p[cc[cnt][len - 1].id];

			for (int j = len - 2; j >= 0; --j) {
				if (suff[cnt][j + 1] + 1 < d[cc[cnt][j].id] + (len - 1 - j)) {
					suff[cnt][j] = d[cc[cnt][j].id] + (len - 1 - j);
					suff_pos[cnt][j] = j;
					old_to_s[cnt][j] = p[cc[cnt][j].id];
				} else {
					suff[cnt][j] = suff[cnt][j + 1] + 1;
					suff_pos[cnt][j] = suff_pos[cnt][j + 1];
					old_to_s[cnt][j] = old_to_s[cnt][j + 1];
				}
			}
			
			for (int j = 1; j < cc[cnt].size (); ++j) {
				if (d[cc[cnt][j].id] < pref[cnt][j - 1] + 1) {
					d[cc[cnt][j].id] = pref[cnt][j - 1] + 1;
					p[cc[cnt][j].id] = -1;
					p2[cc[cnt][j].id] = pref_pos[cnt][j - 1];
				}			
			}
			for (int j = len - 2; j >= 0; --j) {
				if (d[cc[cnt][j].id] < suff[cnt][j + 1] + 1) {
					d[cc[cnt][j].id] = suff[cnt][j + 1] + 1;
					p[cc[cnt][j].id] = -2;
					p2[cc[cnt][j].id] = suff_pos[cnt][j + 1];
				}
			}			
			calced_y = i + 1;
		}
	}
	
	int mx_id = 0;

	for (int i = 1; i <= n; ++i) {
		if (d[mx_id] < d[i])
			mx_id = i;
		//cerr << d[i] << " ";
	}	
	
	//cerr << "\n";
	
	int saved_mx = mx_id;
	
	vector <int> ans;
	
	while (d[mx_id]) {
		if (p[mx_id] == -1) {
			for (int j = pos_in_cc[mx_id]; j != p2[mx_id]; --j)
				ans.emplace_back (cc[num[mx_id]][j].id);
			for (int j = 0; j != p2[mx_id]; ++j)
				ans.emplace_back (cc[num[mx_id]][j].id);
			//ans.emplace_back (cc[num[mx_id]][pref_pos[num[mx_id]][pos_in_cc[mx_id]]].id);
			//mx_id = cc[num[mx_id]][p2].id;
			ans.emplace_back (cc[num[mx_id]][p2[mx_id]].id);
			mx_id = old_to_p[num[mx_id]][p2[mx_id]];
			continue;
		} else if (p[mx_id] == -2) {
			for (int j = pos_in_cc[mx_id]; j != p2[mx_id]; ++j)
				ans.emplace_back (cc[num[mx_id]][j].id);
			for (int j = cc[num[mx_id]].size () - 1; j != p2[mx_id]; --j)
				ans.emplace_back (cc[num[mx_id]][j].id);
			//ans.emplace_back (cc[num[mx_id]][suff_pos[num[mx_id]][pos_in_cc[mx_id]]].id);
			//mx_id = cc[num[mx_id]][suff_pos[num[mx_id]][pos_in_cc[mx_id]]].id;
			ans.emplace_back (cc[num[mx_id]][p2[mx_id]].id);
			mx_id = old_to_s[num[mx_id]][p2[mx_id]];
			continue;
		}
		ans.emplace_back (mx_id);
		mx_id = p[mx_id];
	}
	
	reverse (ans.begin (), ans.end ());
	
	assert (ans.size () == d[saved_mx]);
	
	cout << ans.size () << "\n";
	
	for (auto it : ans)
		cout << it << " ";

	return 0;
}