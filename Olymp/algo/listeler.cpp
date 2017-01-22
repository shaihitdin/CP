using namespace std;

int end[N], nxt[N], pre[N], sz, list_id[N];
/// LAST ELEMENT OF LIST, NXT ELEMENT, PREV ELEMENT, COUNTER, WHICH LIST

inline void add_element (int v) { // At the end of v'th list
	int n_el = ++sz;
	nxt[end[n_list]] = n_el;
	pre[n_el] = end[n_list];
	lst[v] = n_el;
	list_id[n_el] = v;
}

inline void del_element (int num) { // id of element
	int nx = nxt[num], pr = pre[num];
	nxt[pr] = nx;
	pre[nx] = pr;
	if (lst[list_id[num]] == num)
		lst[list_id[num]] = pr;
}

inline void go_through (int v) {
	for (int to = lst[v]; to; to = nxt[to]) {
		cout << to << " ";
	}
}
