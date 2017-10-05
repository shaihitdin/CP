#include <cstring>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <queue>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <complex>

#define pb push_back
#define mp make_pair

#define f first
#define s second

using namespace std;

const int N = (int) 1e3 + 7;

string s;

inline bool ok (string s) {
    return 1;
}

int main() {
    #ifdef LOCAL
        freopen("in.txt", "r", stdin);
    #else
        //#define FNAME
        //freopen(FNAME".in", "r", stdin);
        //freopen(FNAME".out", "w", stdout);
    #endif
    int W;

    cin >> W;
    getline (cin, s);

    getline (cin, s);

    if (!ok (s)) {
        cout << -1;
        return 0;
    }
    int EF = 0, EB = 0, V = 0;
    for (int i = 0; i < s.size (); ++i) {
        if (s[i] == 'S') {
            ++V, ++EF;
        }
        if (s[i] == 'L') {
            EF += 2, ++EB;
            V += 2;
        }
        if (s[i] == 'B') {
            EF += 2;
            V += 2;
        }

    }

    cerr << EF << " " << EB << " " << V << endl;

    cout << EF + W * EB - V + 2;

    return 0;
}
