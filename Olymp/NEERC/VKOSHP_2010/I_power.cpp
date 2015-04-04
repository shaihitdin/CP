#include <bits/stdc++.h>
#include <ext/rope>

using namespace std;
using namespace __gnu_cxx;

const int N = 1e5 + 1, sz1 = 1 << 17;
int b[sz1], a[sz1], n, m;

rope <int> haha;

struct node {
    int sum;
    node *l, *r;
    
    node (const int &x) {
        l = r = 0;
        sum = x;
    }

    node (node *lhs, node *rhs) {
        l = lhs;
        r = rhs;
        sum = lhs -> sum + rhs -> sum;
    }

};


inline int MID (const int &l, const int &r) {
    return (r + l) >> 1;
}

inline int get (node *t, const int &Tl, const int &Tr, const int &l, const int &r) {
    if (Tr < l || Tl > r)
        return 0;
    if (l <= Tl && Tr <= r)
        return t -> sum;
    int mid = MID (Tl, Tr);
    return get (t -> l, Tl, mid, l, r) + get (t -> r, mid + 1, Tr, l, r);
}

inline node * upd (node *o_root, const int &l, const int &r, const int &x, const int &to) {
    if (l == r)
        return new node (to);
    int mid = MID (l, r);
    if (l <= x && x <= mid)
        return new node (upd (o_root -> l, l, mid, x, to), o_root -> r);
    else
        return new node (o_root -> l, upd (o_root -> r, mid + 1, r, x, to));
}

inline node * Build (const int &l, const int &r) {
    if (l == r)
        return new node (b[l]);
    int mid = MID (l, r);
    return new node (Build (l, mid), Build (mid + 1, r));
}

node *roots[N];

vector <int> v[N];
int sz[N];

int main () {
    freopen ("rollback.in", "r", stdin);
    freopen ("rollback.out", "w", stdout);
    scanf ("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf ("%d", &a[i]);
        v[a[i]].push_back(i);
    }
    for (int i = 1; i <= n; ++i)
        b[i] = (v[a[i]][0] == i);
    
    roots[1] = Build (0, sz1 - 1);

    for (int i = 2; i <= n; ++i) {
        roots[i] = upd (roots[i - 1], 0, sz1 - 1, i - 1, 0);
        if (++sz[a[i - 1]] < v[a[i - 1]].size())
            roots[i] = upd (roots[i], 0, sz1 - 1, v[a[i - 1]][sz[a[i - 1]]], 1);
    }
    int q;  
    scanf ("%d", &q);
    
    int p = 0;
    
    for (int i = 1; i <= q; ++i) {
        int l, k;
        scanf ("%d%d", &l, &k);
        l = ((l + p) % n) + 1;
        k = ((k + p) % m) + 1;
        int l_bin = l - 1, r_bin = n + 1;
        while (r_bin - l_bin > 1) {
            int mid = MID (l_bin, r_bin);
            if (get (roots[l], 0, sz1 - 1, l, mid) < k)
                l_bin = mid;
            else
                r_bin = mid;
        }
        if (get (roots[l], 0, sz1 - 1, l, r_bin) == k) {
            printf ("%d\n", r_bin);
            p = r_bin;
        }
        else {
            p = 0;
            printf ("0\n");
        }
    }
    
    return 0;
}