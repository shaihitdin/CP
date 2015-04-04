#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 10;
const double eps = 1 / 1e7;

multiset <double> trap;
double x[N], a[N];
int n, k;
double v1, v2;
double s;

inline bool eq (const double &lhs, const double &rhs) {
    return (rhs - lhs) > -eps && (rhs - lhs) < eps;
}

int main () {
    freopen ("trap.in", "r", stdin);
    freopen ("trap.out", "w", stdout);
    ios_base :: sync_with_stdio (0);
    cin >> n >> k;
    k = min (k, n);
    cin >> v1 >> v2 >> s;
    for (int i = 1; i <= n; ++i)
        cin >> x[i] >> a[i];
    if (s == 0) {
        puts ("0");
        return 0;
    }
    if (v1 >= v2) {
        puts ("inf");
        return 0;
    }
    int can = k;
    double penalty = 0;
    int i = 1;
    while (i <= n && x[i] < s)
        ++i;
    for (; i <= n; ++i) {
        double t1 = (x[i] - s) / v1;
        while (can && trap.size() && (v2 * (t1 - penalty) >= x[i] || eq (v2 * (t1 - penalty), x[i]))) {
            double j = *trap.rbegin();
            penalty += j;
            trap.erase (trap.find (*trap.rbegin()));
            --can;
        }
        if (v2 * (t1 - penalty) >= x[i] || eq (v2 * (t1 - penalty), x[i]))
            break;
        trap.insert (a[i]);
    }   
    while (can && trap.size()) {
        double j = *trap.rbegin();
        penalty += j;
        trap.erase (trap.find (*trap.rbegin()));
        --can;
    }
    cout.precision (10);
    cout << fixed;
    cout << (s + (penalty * v2)) / (v2 - v1);
    return 0;
}