/*
struct tree{
	int sum;
};
tree t1[N*4],t2[N*4],t3[N*4],t4[N*4]; //(in tree) t1 - even +, t2 - odd -, t3 - even -, t4 - odd +
int sz, m, i, x, y;
int a[N];
inline int getsum1(int v,int Tl,int Tr,int l,int r) {
	if(Tl > r || Tr < l) {
		return 0;
	}
	if(Tl >= l && Tr <= r) {
		return t1[v].sum;
	}
	int res = 0;
	int mid = (Tl+Tr) >> 1;
	res += getsum1(v*2, Tl, mid, l, r);
	res += getsum1(v*2+1, mid+1, Tr, l, r);
	return res;
}

inline int getsum2(int v,int Tl,int Tr,int l,int r) {
	if(Tl > r || Tr < l) {
		return 0;
	}
	if(Tl >= l && Tr <= r) {
		return t2[v].sum;
	}
	int res = 0;
	int mid = (Tl+Tr) >> 1;
	res += getsum2(v*2, Tl, mid, l, r);
	res += getsum2(v*2+1, mid+1, Tr, l, r);
	return res;
}

inline int getsum3(int v,int Tl,int Tr,int l,int r) {
	if(Tl > r || Tr < l) {
		return 0;
	}
	if(Tl >= l && Tr <= r) {
		return t3[v].sum;
	}
	int res = 0;
	int mid = (Tl+Tr) >> 1;
	res += getsum3(v*2, Tl, mid, l, r);
	res += getsum3(v*2+1, mid+1, Tr, l, r);
	return res;
}

inline int getsum4(int v,int Tl,int Tr,int l,int r) {
	if(Tl > r || Tr < l) {
		return 0;
	}
	if(Tl >= l && Tr <= r) {
		return t4[v].sum;
	}
	int res = 0;
	int mid = (Tl+Tr) >> 1;
	res += getsum4(v*2, Tl, mid, l, r);
	res += getsum4(v*2+1, mid+1, Tr, l, r);
	return res;
}

inline void upd(int v,int Tl,int Tr, int l, int r, int x) {
	if(Tl > r || Tr < l) {
		return ;
	}
	if(Tl >= l && Tr <= r) {
		if(v&1)
			t2[v].sum = -x, t4[v].sum = x;
		else
			t1[v].sum = x, t3[v].sum = -x;
		return ;
	}
	int mid = (Tl+Tr) >> 1;
	upd(v*2, Tl, mid, l, r, x);
	upd(v*2+1, mid+1, Tr, l, r, x);
	t1[v].sum = t1[v*2].sum + t1[v*2+1].sum;
	t2[v].sum = t2[v*2].sum + t2[v*2+1].sum;
	t3[v].sum = t3[v*2].sum + t3[v*2+1].sum;
	t4[v].sum = t2[v*2].sum + t4[v*2+1].sum;
}
*/
