
#include <iostream>
#include <string>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
 
using namespace std;
 
const int N = 5000;
 
string x[N];
int n, nn;
int ok[N];
 
inline int get_cnt (int i, int j) {
    int cnt = 0;
    for (int k = 0; k < n; ++k) {
        if (x[i][k] == '?' || x[j][k] == '?')
            continue;
        else
            cnt += (x[i][k] != x[j][k]);
    }
    return cnt;
}
 
inline int get_mask (int i) {
    int mask = 0;
    for (int j = 0; j < n; ++j) {
        assert (x[i][j] != '?');
        mask |= ((x[i][j] - '0') << j);
    }
    return mask;
}
 
inline void rec (int lvl) {
    if (lvl == 1) {
    	int check = 0;
        for (int i = 0; i < n; ++i) {
            if (x[lvl][i] != '?')
                continue;
            ++check;
            x[1][i] = '0';
            int mask = get_mask (1);
            ++ok[mask];
            rec (lvl + 1);
            --ok[mask];
            x[1][i] = '1';
            mask = get_mask (1);
            ++ok[mask];
            rec (lvl + 1);
            --ok[mask];
            x[1][i] = '?';
        }
        assert (check == 1);
        return;
    }
    int cnt = get_cnt (lvl, lvl - 1);
    if (cnt > 1)
        return;
    int check = 0;
    for (int i = 0; i < n; ++i) {
        if (x[lvl][i] != '?')
            continue;
        ++check;
        if (cnt == 0)
            x[lvl][i] = x[lvl - 1][i] ^ 1;
        else
            x[lvl][i] = x[lvl - 1][i];
        int mask = get_mask (lvl);
        if (ok[mask]) {
        	x[lvl][i] = '?';
            return;
        }
        ++ok[mask];
        if (lvl == nn) {
            if (get_cnt (1, nn) == 1) {
                cout << "YES\n";
                for (int i = 1; i <= nn; ++i)
                    cout << x[i] << "\n";
                exit (0);
            }
            x[lvl][i] = '?';
            --ok[mask];
            return;
        }
        rec (lvl + 1);
        x[lvl][i] = '?';
        --ok[mask];
    }
    assert (check == 1);
}
 
int main () {
 
    freopen ("gray-code.in", "r", stdin);
    freopen ("gray-code.out", "w", stdout);
 
    cin >> n;
 
    nn = (1 << n);
     
    for (int i = 1; i <= nn; ++i)
        cin >> x[i];
 
    rec (1);
     
    cout << "NO\n";
     
    return 0;
}